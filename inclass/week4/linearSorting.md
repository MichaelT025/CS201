# Linear-Time Sorting (Non-Comparison Sorts)

- Comparison-based sorting has a lower bound of **Omega(n log n)**.
- Examples (comparison-based): Insertion Sort, Merge Sort, Quick Sort, Heap Sort.

These algorithms can beat `n log n` by using assumptions about the keys.



## Counting Sort

- **Idea**: count occurrences of each key, then compute prefix sums to place items into the output.
- **Stable**: yes (when placing items by scanning input from right to left).
- **Time (best/worst/avg)**: `O(n + k)`
- **Space**: `O(n + k)`
- **When to use**: small-ish key range `k` compared to `n`.

### Counting Sort Pseudocode

```py
CountingSort(A, B, k):
    # A: input array of length n, keys in 0..k
    # B: output array of length n
    let C[0..k] be a new array

    for i = 0 to k
        C[i] = 0

    for j = 0 to A.length-1
        C[A[j]] = C[A[j]] + 1

    # C[i] now contains the number of elements equal to i
    for i = 1 to k
        C[i] = C[i] + C[i-1]

    # C[i] now contains the number of elements <= i
    for j = A.length-1 down to 0
        B[C[A[j]]-1] = A[j]
        C[A[j]] = C[A[j]] - 1
```

## Radix Sort (LSD)

- Processes digits from **least significant** to **most significant**.
- **Stable** if the per-digit sorting algorithm is stable (commonly Counting Sort).

### Radix Sort Pseudocode

```py
RadixSort(A, d):
    for i = 1 to d
        stable sort A by digit i
```

- **Time (best/worst/avg)**: `O(d(n + k))` if Counting Sort is used per digit (where `k` is the digit range / base)
- **Space**: `O(n + k)`

## Bucket Sort

### High-level steps

1. Initialize
    - create an array of `m` empty buckets
2. Scatter
    - distribute each element into its bucket using a bucket index function
3. Sort buckets
    - sort each bucket (often Insertion Sort)
4. Gather
    - concatenate buckets in order

- **Stable**: depends (stable if you keep insertion order in buckets and use a stable sort inside each bucket).

### Bucket Sort Pseudocode

```py
BucketSort(A):
    n = A.length
    let B[0..n-1] be an array of empty lists

    for i = 0 to n-1
        idx = BucketIndex(A[i])
        insert A[i] into B[idx]

    for i = 0 to n-1
        sort list B[i] using insertion sort

    concatenate B[0], B[1], ... , B[n-1] into A
```

- use insertion sort when bucket is small.

- Worst Case: O(n^2) time <- with insertion sort
- Best and Average case: O(n + k) time with counting sort


## Quick Summary

| Algorithm | Stable? | Time | Space | Key assumptions |
|---|---|---|---|---|
| Counting Sort | Yes | O(n + k) | O(n + k) | Keys are integers in range `0..k` |
| Radix Sort (LSD) | Yes (if inner sort is stable) | O(d(n + k)) | O(n + k) | `d` digits, base `k` digit range |
| Bucket Sort | Depends | Average: O(n) (ideal) / Worst: O(n^2) | O(n + #buckets) | Inputs are (roughly) uniformly distributed |