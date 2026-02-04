## Traversal

### Depth First Search (DFS)

#### Preorder

Visit the root first, then traverse the left subtree, then traverse the right subtree.

```cpp
void preorder(BinaryTree T){
    preorder(T->root)
}

void preorder(Node *p){
    if(p == NULL) return;
    visit(p);
    preorder(p->leftChild);
    preorder(p->rightChild);
}
```

#### Postorder

Visit the left subtree first, then traverse the right subtree, then visit the root.

```cpp
void postorder(BinaryTree T){
    postorder(T->root)
}

void postorder(Node *p){
    if(p == NULL) return;
    postorder(p->leftChild);
    postorder(p->rightChild);
    visit(p);
}
```

#### Inorder

Visit the left subtree first, then traverse the root, then traverse the right subtree.
```cpp
void inorder(BinaryTree T){
    inorder(T->root)
}

void inorder(Node *p){
    if(p == NULL) return;
    inorder(p->leftChild);
    visit(p);
    inorder(p->rightChild);
}
```

### Breadth First Search (BFS)

#### Level Order Traversal

Visit root then its children, then their children, and so on down the tree level by level.
```cpp
void levelOrder(BinaryTree T){
    levelOrder(T->root)
}

void levelOrder(Node *p){
    queue<Node *> Q;
    
    Q.push(p);
    while(Q.size()>0){
        Node *p = Q.front();
        Q.pop();
        visit(p);
        if(p->leftChild != NULL) Q.push(p->leftChild);
        if(p->rightChild != NULL) Q.push(p->rightChild);
    }
}
```