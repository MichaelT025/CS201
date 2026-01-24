Spring 2026 – CS 201 Data Structures and Algorithms

Homework-0

Execution time for different problem sizes


| Problem Size | Insertion Sort | Merge Sort | std::sort  |
| ------------ | -------------- | ---------- | ---------- |
| 10           | 5.04e-07   | 7.2e-07    | 1.969e-06  |
| 100          | 5.457e-06  | 4.474e-06  | 1.2087e-05 |
| 1,000        | 3.88438e-04 | 6.1941e-05 | 1.58081e-04 |
| 10,000       | 1.94722e-02 | 8.57349e-04 | 1.77172e-03 |
| 100,000      | 1.6768e+00 | 9.54182e-03 | 1.91937e-02 |
| 1,000,000    | 1.69798e+02 | 1.07051e-01 | 1.02875e-01 |
| 10,000,000   | 1.69798e+04 | 1.2396e+00 | 1.23947e+00 |
| 100,000,000  | 1.69798e+06 | 1.46214e+01 | 1.40264e+01 |

1. Based on the execution time in the table above, answer the following questions:

a. For each of the three sort methods, what pattern do you observe in the execution time as the problem size is increased (in other words, if you look at each column in the table above, do you see any patterns in execution time as related to the problem size)? Did you expect to see this pattern? If so, why? If not, then what did you expect to see?

Answer:
Insertion sort should grow much faster than the other two (roughly quadratic), so it is only competitive at very small sizes. Merge sort and std::sort both increase much more slowly, consistent with O(n log n) growth. This pattern is expected from their time complexities.

b. How does the execution time of insertion sort compare with execution time of merge sort for different problem sizes? Explain the difference in execution time.

Answer:
Insertion sort is typically faster only for very small arrays because of low overhead, but it degrades quickly as n grows due to O(n^2) behavior. Merge sort scales better for larger inputs because it is O(n log n), so it becomes much faster than insertion sort as the problem size increases.

c. How does the performance of your insertion sort and merge sort implementations compare with the performance of the std:sort? Explain any similarities or differences you observe.

Answer:
std::sort is comparable to merge sort at larger sizes but is usually a bit faster because it is highly optimized (introsort) and minimizes overhead. Merge sort can be slightly slower due to extra memory and copying. Insertion sort is slower than std::sort for moderate and large sizes, though it may be close for very small inputs.
