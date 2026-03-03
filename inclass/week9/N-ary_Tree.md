# Non Binary Tree

- N-ary tree: each node can have zero or more chld nodes, upto a maximum of N children.

### PsuedoCode

```cpp

class Node{
    ElementType data;
    Node parent, leftmostChild, rightSibling
    //singly-linked list of each node's children
}
class Tree{
    Node root;
}

//using DLL
class Node {
	ElementType data;
	Node parent, leftmostChild, rightmostChild, leftSibling, rightSibling
}
```
## Traversal

### Preorder Traversal
-visit the node, its children then siblings
```cpp
void preorder(Node* n) {
    if (n == nullptr) return;
    visit(n);
    preorder(n->leftmostChild);
    preorder(n->rightSibling);
}
```
### Postorder Traversal
-visit the node's children then the node itself
```cpp
void postorder(Node* n) {
    if (n == nullptr) return;
    postorder(n->leftmostChild);
    visit(n);
    postorder(n->rightSibling);
}
```

### Level-order Traversal
-visit the nodes level by level, from left to right
```cpp
void levelorder(Node* n) {
    if (n == nullptr) return;
    Queue q;
    q.enqueue(n);
    while (!q.isEmpty()) {
        Node* current = q.dequeue();
        visit(current);
        Node* child = current->leftmostChild;
        while (child != nullptr) {
            q.enqueue(child);
            child = child->rightSibling;
        }
    }
}
```

- no meaningful inorder traversal for an N-ary tree