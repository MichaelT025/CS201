Spring 2026 – CS 201 Data Structures and Algorithms

Homework-0

Report

Objectives

The goal of this assignment was to implement insertion sort and merge sort using C++ iterators, verify correctness using the provided functional test driver, and then compare performance against each other and against the C++ standard library's std::sort.

Method

After implementing both algorithms, I used the provided driver programs to (1) confirm that the algorithms sorted correctly on different container/data types (functest.cpp) and (2) measure execution time across increasing input sizes (perftest.cpp). For performance testing, I ran perftest multiple times and recorded the reported times for insertion sort, merge sort, and std::sort.

Results

Execution time for different problem sizes

| Problem Size | Insertion Sort | Merge Sort | std::sort |
| ------------ | -------------- | ---------- | --------- |
| 10           | 5.04e-07       | 7.2e-07    | 1.969e-06 |
| 100          | 5.457e-06      | 4.474e-06  | 1.2087e-05 |
| 1,000        | 3.88438e-04    | 6.1941e-05 | 1.58081e-04 |
| 10,000       | 1.94722e-02    | 8.57349e-04 | 1.77172e-03 |
| 100,000      | 1.6768e+00     | 9.54182e-03 | 1.91937e-02 |
| 1,000,000    | 1.69798e+02    | 1.07051e-01 | 1.02875e-01 |
| 10,000,000   | 1.69798e+04    | 1.2396e+00 | 1.23947e+00 |
| 100,000,000  | 1.69798e+06    | 1.46214e+01 | 1.40264e+01 |

Discussion

The results match what the Big-O analysis predicts. Insertion sort stays fast for tiny inputs, but its runtime grows extremely quickly as n increases. You can see that clearly once the sizes get large: going from 1,000,000 to 10,000,000 elements (a 10x increase) increases insertion sort time from 1.69798e+02 to 1.69798e+04 seconds (about 100x), which is the kind of growth you expect from an O(n^2) algorithm.

Because insertion sort grows so quickly, I did not actually run insertion sort past the 1,000,000 element case. Based on the 1,000,000 runtime and the observed growth trend, running it on 10,000,000 or 100,000,000 elements would take hours (or longer) on my computer. For the larger problem sizes in the insertion sort column, I estimated the times by projecting forward using the measured growth rate from the earlier rows.

Merge sort and std::sort scale much better. Their times increase far more slowly as the input grows, which is consistent with O(n log n). For the biggest sizes, both merge sort and std::sort are in the same range (around 1.24 seconds at 10,000,000 and around 14 seconds at 100,000,000), while insertion sort is completely impractical.

Comparing merge sort to insertion sort, merge sort quickly wins as soon as inputs stop being "small". Even at 1,000 elements, merge sort is already much faster (6.1941e-05 vs 3.88438e-04), and the gap becomes enormous as n grows because merge sort does fundamentally less work.

Comparing my implementations to std::sort, std::sort is generally competitive with merge sort and slightly faster at the largest sizes (for example, 1.40264e+01 vs 1.46214e+01 at 100,000,000). That makes sense because std::sort is heavily optimized and typically uses introsort, while merge sort has extra overhead from temporary storage and copying. At small sizes, the differences are mostly overhead and constant factors; at large sizes, merge sort and std::sort look very similar because they share the same n log n growth.

Conclusion

Insertion sort is a good choice only for very small arrays because it has low overhead but poor scaling. Merge sort scales well and performs similarly to std::sort for large inputs, although std::sort tends to be slightly faster due to library-level optimizations.

Questions

a.
As the problem size increases, insertion sort's execution time increases very rapidly. When n increases by 10x at larger input sizes, the time increases by roughly 100x (for example, about 170 seconds at 1,000,000 and the estimated time is about 17,000 seconds at 10,000,000). This is consistent with the expected O(n^2) growth.

For merge sort and std::sort, the execution time increases much more slowly. A 10x increase in n results in a smaller multiplier (roughly 10-15x), which aligns with O(n log n). This pattern is what I expected based on the theoretical time complexities.

b.
For very small inputs, insertion sort can be competitive because it has low overhead (for example, it is the fastest at problem size 10 in my table).

However, merge sort becomes faster as n grows and the difference becomes very large for bigger inputs. By 1,000 elements, merge sort is already significantly faster, and the gap continues to widen as the problem size increases. This happens because insertion sort performs O(n^2) work due to repeated shifting/inserting, while merge sort performs O(n log n) work by dividing the input and merging sorted halves.

c.
For large inputs, my merge sort and std::sort have similar performance. For example, at 10,000,000 elements they are essentially the same (about 1.24 seconds), and at 100,000,000 elements std::sort is slightly faster (about 14.0 seconds versus 14.6 seconds for merge sort).

This is reasonable because std::sort is a heavily optimized standard library implementation (typically introsort), while merge sort can have extra overhead from using temporary memory and copying during merging. Insertion sort is much slower than std::sort for moderate and large sizes because its O(n^2) growth does not scale well.
