# CS 201 Homework 3 Report

**Name:** Michael Tesfaye  
**Email:** mktesfaye@crimson.ua.edu  
**Course Section:** Spring 2026 CS 201 – 002

---

## Performance Results

| DB File | # of records | Time taken to create data structure | Time taken to search | Total time taken |
|---------|-------------|-------------------------------------|---------------------|------------------|
| dbfile1.txt | 442 | 0.0105091 | 2.0038e-05 | 0.0105292 |
| dbfile2.txt | 7,065 | 0.215071 | 7.6467e-05 | 0.215148 |
| dbfile3.txt | 14,129 | 0.436941 | 6.7410e-05 | 0.437008 |

Times were measured by compiling with `g++ -O2`, running 5 times per db file, discarding the first run, and averaging the remaining 4. Print statements in the query loop were commented out to avoid I/O overhead skewing the timing.

### Program Output

**dbfile1.txt:**
```
$ ./movie_actor dbfile1.txt query.txt
Number of records: 442
Time to build maps: 0.0105551 seconds
Time to answer queries: 1.9266e-05 seconds
Total time taken: 0.0105744 seconds
```

**dbfile2.txt:**
```
$ ./movie_actor dbfile2.txt query.txt
Number of records: 7065
Time to build maps: 0.221866 seconds
Time to answer queries: 6.2028e-05 seconds
Total time taken: 0.221928 seconds
```

**dbfile3.txt:**
```
$ ./movie_actor dbfile3.txt query.txt
Number of records: 14129
Time to build maps: 0.462129 seconds
Time to answer queries: 6.4181e-05 seconds
Total time taken: 0.462193 seconds
```

---

## Data Structure Rationale

The program uses two `std::unordered_map<string, vector<string>>` instances:

- **`bymovie`** — maps each movie name to a vector of its actors
- **`byactor`** — maps each actor name to a vector of their movies

`unordered_map` was chosen because it provides **O(1) average-case** lookup, insertion, and access via hash-based indexing. Since the problem requires searching by either movie or actor name, maintaining two maps allows constant-time retrieval in either direction. A tree-based `std::map` would give O(log N) per operation, which is unnecessary here since we do not need sorted output.

---

## Algorithm

1. **Build phase:** Read each line from the db file. Split on `/` using regex tokenization. The first token is the movie name; all subsequent tokens are actor names. For each actor, insert the movie into `byactor[actor]` and insert the actor into `bymovie[movie]`.

2. **Search phase:** For each query in the query file, look it up in both `byactor` and `bymovie`. If found in either (or both), print the corresponding vector. If not found in either, print a "Not Found" message.

---

## Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Building maps (per record) | O(A) where A = number of actors in that record |
| Building maps (total) | O(N) where N = total movie-actor pairs across all records |
| Single query lookup | O(1) average (hash table lookup) |
| All queries | O(Q) where Q = number of queries |

Overall complexity: **O(N)** for building + **O(Q)** for searching.

---

## Comparison of Search Times

Search times remain nearly constant across all three db files (~20–77 microseconds), despite the number of records increasing from 442 to 14,129. This confirms the O(1) average-case lookup property of `unordered_map` — once the hash table is built, the size of the dataset does not significantly affect individual query performance.

---

## Explanation of Results

- **Build time scales linearly:** The time to create the data structure grows roughly proportional to the number of records (442 → 7,065 → 14,129), as expected for O(N) insertion. The build time is dominated by regex tokenization and hash map insertions.

- **Search time is effectively constant:** Query times are orders of magnitude smaller than build times and do not grow with dataset size. This demonstrates the efficiency of hash-based lookup for this problem.

- **Build time dominates total time:** Over 99.9% of total execution time is spent building the maps. This is expected since building requires reading and parsing every record, while searching only processes the fixed set of queries in the query file.

---

## Conclusion

Using dual `unordered_map` instances provides an efficient solution for bidirectional movie-actor lookup. The O(1) average-case search makes query performance independent of dataset size, while the linear build cost is a one-time expense. The results confirm that hash-based data structures are well-suited for search and retrieval problems where sorted order is not required.