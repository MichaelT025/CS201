# B-Trees

Objective:

- minimize the number of disk accesses
    - high branching factor
    - shallow tree depth

## Properties of a B-Tree

1. Every node has the following attributes:

   - x->n : the number of keys stored in node x
   - keys stored in monotonically increasing order
   - x->leaf : a boolean value indicating whether the node is a leaf (true for leaf)
1. Each internal node x contains x->n + 1 pointers to its children
1. The keys x.key separate the ranges of keys stored in each subtree:

   k[1] < x.key[1]<k[2]<x.key[2]<k[3]<...<x.key[n]<k[n+1]

3. All levels have the same depth
4. Nodes have lpwer and upper bounds on the number of keys they can contain, expressed in terms of a fixed integrer t>=2 called the min deree of the B-tree:
   a. Every node other than the root must have at least t-1 keys. Every internal node other than the root thus has at least t children. If the tree is nonempty, the root must have at least one key.
   b. Every node can contain at most 2t-1 keys. Therefore, an internal node may have at most 2t children.
        A node is "full" if it contains exactly 2t-1 keys.
5. 




## Search Operation 

```cpp
B_Tree_Search(x,k){
   i=1;
   while i<x.n and k>x.key[i]{
      i++;
      if i<=x.n and k==x.key[i]
         return(x,i)
      else if x.leaf
         return NIL
      else Disk_Read(x.c[i])
   }
   return B_Tree_Seach(x,c[i],k)
}
```

## Create

```cpp
B_Tree_Create(T){
   x=Allocate_Node()
   x.leaf=true
   x.n=0
   Disk_Write(x)
   T.root=x
}
```

## Insert

```cpp
B_Tree_Insert(T,k){
   r=T.root
   if r.n ==2t-1
      s=B_Tree_Split_Root(T)
      B_Tree_Insert_NonFull(s,k)
   else B_Tree_Insert_NonFull(r,k)
}

B_Tree_Insert_NonFull(x,k){
   i=x.n
   if(x.leaf){
    while i>=1 and k< x.key[i]{
      x.key[i+1] = x.key[i]
      i--
    }
    x.key[i+1] = k
    x.n++
   }
   else{
      while i>=1 && k<x.key[i]{
         i--
      }
      i++
      Disk_Read(x.c[i])
      if x.c[i].n == 2t-1{
         B_Tree_Split_Child(x,i)
         if k> x.key[i]{
            i++
         }
      }
      B_Tree_Insert_NonFull(x.c[i],k)
   }
}
```