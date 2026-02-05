- need inorder with one other traversal to build a unique tree
- Step 1: Identify root (use one of the other traversals)
- Step 2: Identify left and right subtrees (use inorder)
- Step 3: Recursively apply steps 1 and 2.

### From Preorder

Example:

Preorder: ABDEHCFJG

Inorder: DBHEAFJCG

root: A (from preorder)

left:   BDEH (from preorder)
        DBHE (from inorder)
right:  CFJG (from preorder)
        FJCG (from inorder)

```
          A
        /   \
    DBHE   FJCG

```

root left: B

left: D

right: E

E's left: H

root right: C

left: F

right: G

F's right: J

```
           A
         /   \
        B     C
       / \   / \
      D   E F   G
         /   \
        H     J
```

### From Postorder

Postorder: DHEBJFGCA

Inorder: DBHEAFJCG

root: A (from postorder)

left: DBHE (from inorder)

right: FJCG (from inorder)

```
          A
        /   \
    DBHE   FJCG

```

root left:B

left: D

right: E

E's left: H

root right: C

left: F

right: G

F's right: J

```
        A    # fix tree
      /   \
     B     C
    / \   / \
   D   E F   G
      /   \
     H     J

```

### From Level Order

Level Order: ABCDEFGHJ

Inorder: DBHEAFJCG

root: A (from level order)

left: DBHE (from inorder)

right: FJCG (from inorder)

***keep the order of the nodes in the level order traversal***

left: BDEH

right: CFJG

```
          A
        /   \
    BDEH   CFJG 
```

left root: B

left: D

right: E

E's left: H

right root: C

left: F

right: G

F's right: J

```
       A
     /   \
    B     C
   / \   / \
  D   E F   G
     /   \
    H     J
```

---

_Refer to Slides for step by step tree building_