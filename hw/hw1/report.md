# CS 201 Homework 1 Report

**Name:** Michael Tesfaye  
**Email:** mktesfaye@crimson.ua.edu  
**Course Section:** Spring 2026 CS 201 – 002

---

## Performance Results

Performance experiments were run on the CS intro server using:

```bash
g++ -std=c++17 -O2 wordcount.cpp -o wordcount
```

The `-O2` optimization flag was used so the measured runtime reflects algorithm behavior with standard compiler optimizations enabled.

Each input file was executed 10 times, and the table below reports the average runtime.

| Input File | # of Distinct Words | Average Time Taken (seconds) |
| ---------- | ------------------: | ---------------------------: |
| input1.txt | 20                  | 0.000185                     |
| input2.txt | 9,895               | 0.253491                     |
| input3.txt | 19,712              | 0.393735                     |

## Performance Analysis

The runtime increases as input size increases, which is expected. `input1.txt` is very small and completes almost instantly. `input2.txt` and `input3.txt` are much larger, and runtime increases from approximately 0.253 s to 0.394 s while the number of distinct words grows from about 9.9k to 19.7k.

This growth pattern is consistent with the expected `O(N log N)` behavior: runtime increases with input size, but not at a quadratic rate. A substantial portion of time for large files is spent during parsing/tokenization, while map operations and sorting contribute the expected logarithmic factors.

## Algorithm Description

The program uses the following steps:

1. **Parsing input text**
   - Read the file line by line using `getline()`.
   - Tokenize each line into words using `istringstream` and `std::sregex_token_iterator`.
   - Store tokens in a `std::vector<std::string>`.

2. **Counting word frequencies**
   - Use `std::map<std::string, int>` to count occurrences of each word.
   - Each insertion/update in `std::map` is `O(log U)`, where `U` is the number of unique words.

3. **Grouping by frequency**
   - Use `std::map<int, std::vector<std::string>>` to group words that share the same count.

4. **Sorting tied words alphabetically**
   - Sort each frequency bucket (`std::vector<std::string>`) with `std::sort`.

5. **Output order**
   - Iterate through the frequency map in reverse order so higher frequencies are printed first.
   - For equal frequencies, words are printed in alphabetical order.

## Worst-Case Complexity Justification: O(N log N)

Let:
- `N` = total number of words read from the file
- `U` = number of unique words (`U <= N`)

| Step            | Operation                                              | Complexity |
| --------------- | ------------------------------------------------------ | ---------- |
| Parsing         | Read and tokenize N words                              | O(N)       |
| Counting        | N inserts/updates in `std::map<string, int>`          | O(N log U) |
| Grouping        | U inserts in `std::map<int, vector<string>>`          | O(U log U) |
| Sorting buckets | Sort all words across buckets                          | O(U log U) |
| Output          | Print grouped words                                    | O(U)       |

Total complexity:

`O(N log U + U log U) = O(N log N)` in the worst case (when `U = N`).

Using `std::map` is important for this assignment because it guarantees `O(log N)` worst-case operations (balanced tree behavior), unlike `std::unordered_map`, which has `O(N)` worst-case operations under collisions.