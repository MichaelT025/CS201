

# Red Black Trees

## Balanced Tree
- a balanced tree is a type of binary tree that maintans its height to be as low as possible while elements are added or removed
- maintain height of O(log n) where n is the number of nodes

## Red Black Trees
- a self-balancing BST


### Properties of Red Black Trees

1. Every node is either red or black
2. The root is black
3. Every leaf (NILL) is black
4. If a node is red, then both its children are black
5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes


- Search: O(log n)
- Insert: O(log n)
- Delete: O(log n)
*** Balancing the tree ensures that the height of the tree is always O(log n) ***

```cpp
class Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    char color;
}

```

### Rotation functions:
- leftRotate when the tree becomes right heavy
- rightRotate when the tree becomes left heavy

### LeftRotate Psuedocode
```cpp
    x
      \  
       y
     /   \
     a    b
leftRotate(T,x){
    y=x.right;
    // set y's left child to x's right child
    x.right=y.left;
    //if it's a NIL node, set 
    if y.left!=T.nil
        y.left.p=x;
    y.p=x.p;
    if x.p==T.nil
        T.root=y;
    else if x==x.p.left
        x.p.left=y;
    else
        x.p.right=y;
    y.left=x;
    x.p=y;
}
     y
    / \
    x  b
     \
      a
```

### RightRotate Psuedeocode
```cpp

rightRotate(T,y){
    x=y.left;
    y.left=x.right;
    if x.right !=T.nil 
        x.right.p=y;
    x.p=y.p
    if y.p==T.nil
        T.root=x;
    else if y==y.p.right
        y.p.right=x;
    else
        y.p.left=x;
    x.right=y
    y.p=x    
}
```

### Insertion

- Insert Node(z) at the correct position
- 4 scenarios:
0. z is root
    - color z black
1. z's uncle is red
    - recolor parent, grandparent and uncle
2. z's uncle is black and (triangle)
```cpp
         B
      /    \
     C      A
           /
          Z 

//B A Z form a triangle (grandparent, parent, child)
```
    -  Rotate parent opposite direction of Z

3. z's uncle is black and (line)
```cpp
         B
      /    \
     C      A
             \
              Z 
//B A Z form a line (grandparent, parent, child)
```
    - Rotate grandparent opposite direction of Z

### Psudocode
```cpp
treeInsert(T,z){
    y=T.nil
    x=T.root
    while(x!=T.nil){
        y=x
        if(z.key<x.key)
            x=x.left
        else
            x=x.right
    }
    z.p=y
    if(y==T.nill)
        T.root=z
    else if(z.key<y.key)
        y.left=z
    else
        y.right=z
    z.left=T.nil
    z.right=T.nil
    //always color red at insertion
    z.color=RED
    Insert_Fixup(T,z)
}

Insert_Fixup(T,z){
    while(z.p.color==RED){
        if (z.p==z.p.p.left){ //check which side we are on
            y=z.p.p.right //y is z's uncle (the other side of the grandparent)
            if(y.color==RED){ //case 1: z's uncle is red
                //recolor parent, grandparent and uncle
                z.p.color=BLACK
                y.color=BLACK
                z.p.p.color=RED
                z=z.p.p
            }
            else if(z==z.p.right){
            //case 2 z'suncle is black (triangle)
            z=z.p
            left_Rotate(T,z)
            }
            //case 3 z's uncle is black (line)
            z.p.color=BLACK
            z.p.p.color=RED
            right_Rotate(T,z.p.p)
        }
        else{ //same operation if z is part of its grandparents right side
            ....
        }
    }
    T.root.color==BLACK

}
```


### Deletion

- If z has no children then simply remove it by modifying its parent's pointer to NIL
- If z has one child, elevate the child to take z's position in the tree by modifying z's parent to point to z's child
- If z has two children, find z's successor y, copy y's contents to z, and then delete y

```cpp
RB_Delete(T,z){
    y=z
    y.original_color=y.color
    if z.left==T.nil
        x=z.right
        RB_Transplant(T,z,z.right)
    else if z.right==T.nil
        x=z.left
        RB_Transplant(T,z,z.left)
    else 
        y=Treemin(z.right) //find successor
        y.original_color=y.color
        x=y.right
        if y.p==z
            x.p=y
        else
            RB_Transplant(T,y,y.right)
            y.right=z.right
            y.right.p=y
        RB_Transplant(T,z,y)
        y.left=z.left
        y.left.p=y
        y.color=z.color
    if y.original_color==black
        RB_DeleteFixup(T,x)
}
RB_Transplant(T,u,v){ //sever u from the tree
    if u.p==T.nil
        T.root=v
    else if u==u.p.left
        u.p.left=v
    else
        u.p.right=v
    v.p=u.p
}
Treemin(x){

}
RB_DeleteFixup(T,x){
 while x!=T.root and x.color==black
    if x==x.p.left
        w=x.p.right   
    else
        w=x.p.left
}
