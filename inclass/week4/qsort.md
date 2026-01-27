## Pseudocode:

```py
quicksort(A(array),p(int),r(int))
    if p<r
        q=Partition(A,p,r)
        quicksort(A,p,q-1)
        quicksort(A,q+1,r)

Partition(A(array),p(int),r(int))
    x=A[r]
    i=p-1
    for j=p to r-1
        if A[j]<=x
            i=i+1
            exchange A[i] with A[j]
    exchange A[i+1] with A[r]
    return i+1
```

### Pivot Selection

Choosing a good pivot is crucial for the performance of Quick Sort. A bad choice can lead to worst-case performance of O(n^2) time.

#### Worst Case

* Sorted or Reverse Sorted Arrays
* Worst case: O(n^2) time
* T(n) = T(n-1) + T(0) + O(n)

#### Average Case

* Average case: O(nlogn) time
* T(n) = 2T(n/2) + O(n)

#### Choosing a Good Pivot

* Randomized pivot selection
* Choose median of three (first, middle, last) as the pivot

#### Complexity and Stability

* Time complexity:
	+ Worst case: O(n^2)
	+ Average case: O(nlogn)
* Space complexity: O(logn)
* Stability: Not stable (standard in-place partition)