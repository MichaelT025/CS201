# B_Trees

## Proterties

- Each node has n keys (x->n)
- keys are stored in increasing order
- Internal nodes have n+1 children
- all leaves are at the same depth
- the keys separate the ranges of keys stored in each subtree:
  k[1]<x.key[1]<k[2]<x.key[2]<k[3]<...<x.key[n]<k[n+1]
- every node has a lower and upper bound on the number of keys it can contain

***Lower Bound ***

- at least t-1 keys

internal nodes: at least t children

***Upper Bound***

- at most 2t-1 keys

internal nodes: at most 2t children

t is called the minimum degree of the B-tree and t>=2

### Code 

```cpp
class Node{
    int *keys;       // Array of keys
    Node **children; // Array of child pointers
    int n;           // Current number of keys
    bool leaf;       // True if node is a leaf
    
    Node(bool _leaf) {
        leaf = _leaf;
        keys = new int[2*t - 1];
        children = new Node*[2*t];
        n = 0;
    }
};

class BTree{
    Node *root;
    int t; //Minimum degree
    BTree(int _t){
        this->root=nullptr;
        this->t=_t;
    }
};

```

## Search 

```cpp
B_Tree_Search(x, k) {
   i = 1;
   while i <= x.n and k > x.key[i] { //loop through current node keys 
      i++;
   }
   if i <= x.n and k == x.key[i]
      return (x, i)             // Found the key
   else if x.leaf
      return NIL               // Not found, at leaf
   else {
      Disk_Read(x.c[i])        // Load child from disk
      return B_Tree_Search(x.c[i], k)  // Recurse into child
   }
}
```

## Insertion

- split full nodes
- insert median into parent

```cpp
B_Tree_insert(T,k){
    r=T.root
    if r.n==2t-1{       //if root is full
        s=split_root(T)
        B_Tree_insert_nonfull(s,k)
    }
    else B_Tree_insert_nonfull(r,k)

}

split_root(T){      //create a new root then split children
    s= new Node()
    s.leaf=false
    s.n=0
    s.c1=T.root
    T.root=s
    split_child(s,1)
    return s;
}
split_child(x,i){
// take median value, send it up to parent
// split its left side as a left child
//split the right side as a right child
}

B_Tree_insert_nonfull(x,k){
    if leaf insert key at correct position
    else split_child(x,i)
        B_Tree_insert_nonfull(x.c[i],k)
}
```

## Deletion (the big one)

### Case 1: Search arrives at a leaf node with at least t keys

- just delete the key from the node

### Case 2: Search arrives at an internal node that contains key k

#### Case 2a: x.c[i] has at least t keys

- use predecessor method

#### Case2b: x.c[i] has min keys but x.c[i+1] hass at least t keys

- use the successor method

#### Case 2c: both x.c[i] and x.c[i+1] have min keys(t-1)

- merge x.c[i] and x.c[i+1]
- delete k

### Case 3: The search arrives at an internal node that doesn't contain key k

- ensure an internal node has at least t keys before descending

#### Case 3a: x.c[i] has min keys but has an immediate sibling with at least t keys

- bring a key down from parent into x.c[i]
- move a key up from x.c[i+1]
- delete k

#### Case 3b: x.c[i] and its immediate siblings have min keys

- merge x.c[i] with one of its siblings
- bring a key down from x to have the median node