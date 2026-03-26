# Red Black Trees

## Properties

    1. Every node is either red or black
1. The root is black
2. Every leaf (NILL) is black
3. If a node is red, then both its children are black
4. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes

## Operations

### Rotations

- rotations are use to help fix the tree after insertion or deletion.

#### Code

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

### Insertions

- Insert Node(z) at the correct position
- Color z red
- violation occurs when z's parent is red
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

- Rotate away from Z at parent

3. z's uncle is black and (line)

```cpp
         B
      /    \
     C      A
             \
              Z 
//B A Z form a line (grandparent, parent, child)
```

- color parent black
- color grandparent red
- Rotate away from Z at grandparent
- Finally color the root black

#### Fixup Pseudocode

```cpp
Insert_Fixup(T,z){

    /*
    Essentialy the idea is to change every other case to case 3 as that is the final step to fix the violation
    */
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
            else if(z==z.p.right){ //case 2 z'suncle is black (triangle)
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

- if node is leaf just remove it
- if node only has one child elevate that child up
- if node has two children, use **the successor**
- violation occurs when removed node (not intended node) is black
- 4 cases:

1. sibling(w) is red

   - recolor sibling and parent
   - rotate towards x at parent
1. sibling and its children are black

   - recolor sibling
   - set parent as new w (elevate issue up the tree)
1. sibling is black and inner child is red

   - recolor sibling and inner child
   - rotate away from x at w
1. sibling is black and siblings outer child is red

   - recolor parent, sibling and outer child
   - rotate towards x at parent

- finally color x black

#### Fixup Pseudocode

```cpp
Delete_Fixup(T,x){
    while(x!=T.root && x.color==BLACK){
        if(x==x.p.left){ //check if we are on left side
            w=x.p.right  //w is the sibling
            if(w.color==RED){   //case 1: sibling is red
                w.color=BLACK
                x.p.color=RED
                left_Rotate(T,x.p)
                w=x.p.right     //
            }
            if(w.left.color==BLACK && w.right.color==BLACK){    //case 2: sibling and its children are black
                w.color=RED
                x=x.p
            }
            else{
                if (w.right.color==BLACK){ //case 3: sibling is black and inner child is red
                    w.left.color=BLACK
                    w.color=RED
                    right_Rotate(T,w)
                    w=x.p.right
                }
                //case 4: sibling is black and siblings outer child is red
                w.color=x.p.color
                x.p.color=BLACK
                w.right.color=BLACK
                left_Rotate(T,x.p)
                x=T.root
            }
        }
    }
    x.color=BLACK
}
```