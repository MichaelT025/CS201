## Trees

- Root Node: the topmost node in a tree
- Parent Node: any node that has one or more child nodes
- Child Nodes: any node that has a parent node above it
- Leaf Node: nodes with no children
- Edges: connections between nodes in a tree
- the degree of a node refers to the number of children it has

## Binary Trees

- degree no greater than two
- every node is defined as either the left child or the right child of its parent
- consists of the root and then the left and right subtrees

## Heaps

- Heaps are binary trees satisfying two conditions.

  **Heap property**
    - **Min heap**: parent node <= child node
                : root is the smallest element
  **Max heap**: parent node >= child node
              : root is the largest element

  Complete Binary Tree: all levels except possibly the last one are completely filled
  The last level is filled from left to right without any gaps.

- Heap is usually implemented using an array.
- maxheapify runs in O(log n)

One Indexed: 
Parent Node=**i**
Left child=2i
Right child =2i+1

Zero Indexed: 

Parent Node=**i**

Left child=2i+1

Right child =2i+2

- Heap height is O(logn).
- build max heap= O(n)
- HeapSort phase= O(nlogn)

```cpp
buildmaxheap(vector<int>& A){
    for(int i=A.size()/2;i>=1;i--){
        maxheapify(A,i);
    }
}

maxheapify(vector<int> &A, int i){
    int l=2*i;//left child
    int r=2*i+1;//right child
    int largest;
    if (l<=A.size()&&A[l]>A[i])
        largest=l;
    else
        largest=i;
    if (r<=A.size()&&A[r]>A[largest])
        largest=r;
    if(largest!=i){
        swap(A[i],A[largest]);
        maxheapify(A,largest);
    }
}

void heapsort(vector<int> &A){
    buildmaxheap(A);
    for(int i=A.size();i>=2;i--){
        swap(A[1],A[i]);
        maxheapify(A,1);
    }
}


```