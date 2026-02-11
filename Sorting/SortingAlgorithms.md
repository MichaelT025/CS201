# Non Comparison Sorts

## Insertion Sort

- works by building the final sorted array one item at a time
- gets a key and compares it to the items in the array then inserts it in the correct position

### Pseudocode
```cpp

insertionSort(array A){
  for(int i=1;i<A.size();i++){
    int key=A[i]
    int j=i-1;
    while(j>=0 && A[j]>key){
      A[j+1]=A[j]
      j--;
    }
    A[j+1]=key;
  }
}

```
Average Case: O(n^2)
Best Case: O(n)  when the array is already sorted
Worst Case: O(n^2) when the array is sorted in reverse order

Space Complexity: O(1) In place
Stable: Yes


## Merge Sort

- divide and conquer algorithm
- divide the array into two halves
- sort each half recursively
- merge the two halves

### Pseudocode
```cpp



merge(array A, int lo, int mid, int hi){
    int L=mid-lo+1;
    int R=hi-mid;
    array left[L];
    array right[R];
    for(int i=lo to mid){
      left[i-lo]=A[i];
    }
    for(int i=mid+1 to hi){
      right[i-mid-1]=A[i];
    }
    int leftp=0;
    int rightp=0;
    int mergep=lo;
    while(leftp<=L && rigthp<=R){
      if(left[leftp]<=right[rightp]){
       A[mergep]=left[leftp];
       leftp++;
      }
      else{
        A[mergep]=right[rightp];
        rigthp++;
      }
      mergep++;
    }
    while(leftp<L){
      A[mergep]=left[leftp];
      leftp++;
      mergep++;
    }    
    while(rightp<R){
      A[mergep]=right[rightp];
      rightp++;
      mergep++;
    }    
}


mergeSort(array A,int lo, int hi){
    if(hi<=lo) return;
    int mid=lo+(hi-lo)/2;
    mergeSort(A,lo,mid);
    mergeSort(A,mid+1,hi);
    merge(A,lo,mid,hi);
}
```
Average Case: O(nlogn)
Best Case: O(nlogn)
Worst Case: O(nlogn)

Space Complexity: O(n) Not in place
Stable: Yes

## Quick Sort

- also divide and conquer
- divide the array by partitioning it into two subarrays
- after one pass the pivot is in the correct position
- sort the two subarrays recursively

### Pseudocode
```cpp

partition(array A, int low, int high){
  int pivot=A[high];
  int i=low-1;
  for(int j=low to high-1){
    if(A[j]<=pivot){
      i++;
      swap(A[i],A[j]);
    }
  }
  i++;
  swap(A[i],A[high]);
  return i;
}

quicksort(array A, int low, int high){
    if(low<high){
        q=partition(A,low,high)
        quicksort(A,low,q-1)
        quicksort(A,q+1,high)
    }
}

```
Average Case: O(nlogn)
Best Case: O(nlogn)
Worst Case: O(n^2) unbalanced partitioning (when the array is sorted or reverse sorted)
Space Complexity: O(logn) Not in place <- successive function calls on the call stack
Stable: No

## Heap Sort

- works by building a max heap from the array
- then reccursively swaps the root with the last element and heapifies the remaining array

### Pseudocode
```cpp

heapify(Array A, int i){
  int lc=2*i;
  int rc=2*i+1;
  int largest=i;
  if(lc<A.size()&&A[lc]>A[largest])
    largest=lc;
  if(rc<A.size()&&A[rc]>A[largest])
    largest=rc;
  if(largest!=i){
    swap(A[i],A[largest]);
    heapify(A,largest);
  }
}


buildmaxheap(array A){
    for(int i=A.size()/2;i>=0;i--){
        maxheapify(A,i)
    }
}
heapsort(array A){
    buildmaxheap(A)
    for(int i=A.size()-1;i>0;i--){
        swap(A[0],A[i])
        heapify(A,0)
    }
}

```
Average Case: O(nlogn)
Best Case: O(nlogn)
Worst Case: O(nlogn)
Space Complexity: O(1) In place
Stable: No


# Linear (Comparison Based) Sorting

## Counting Sort

```cpp

```
Average Case: O(n+k)
Best Case: O(n+k)
Worst Case: O(n+k)
Space Complexity: O(k) Not in place
Stable: Yes

## Radix Sort

```cpp

radixsort(array A){
  for(i to A.size()){
    //use stable sort to sort array based on ith digit
    stableSort(A,i);
  }   
}
```


## Bucket Sort

```cpp

bucketSort(array A){
  n=A.length
  let B[0..n-1] be a new array
  for i to n-1{
    B[i]=A[i]
  }
}
```