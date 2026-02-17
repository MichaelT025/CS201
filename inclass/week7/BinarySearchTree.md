# Binary Search Tree

- nodes in the left subtree are less than the root
- nodes in the right subtree are greater than the root
- left and right subtrees are also binary search trees

### Implementation
```cpp

class Node{
    int data;
    Node* left;
    Node* right;
    Node(int data): data(data), left(nullptr), right(nullptr){}

}

class BinarySearchTree{
    Node* root;
    BinarySearchTree(): root(nullptr){}
}
```

### Operations

#### Find
```cpp
    bool find(int data){
        return find(root, data);
    }
    bool find(Node* root, int data){
        if(root == nullptr) return false;
        if(root->data == data) return true;
        if(data < root->data) return find(root->left, data);
        return find(root->right, data);
    }
```

#### Insert

```cpp
    void insert(int data){
        root = insert(data, root);
    }

    Node* insert(int data, Node* root){
        if(root == nullptr){
            root = new Node(data);
        }
        if(data < root->data) root->left = insert(root->left, data);
        root->right = insert(root->right, data);
        return root;
    }
```

#### Remove
```cpp
void remove(int x){
    root=remove(x,root);
}
Node* remove(int x, Node* root){
    if(root==null){
        cout<<"key not found"<<endl;
        return nullptr;
    }
    if(x<root->data) root->left=remove(x,root->left);
    else if(x>root->data) root->right=remove(x,root->right);
    else if(root->left==null)
        return root->right;
    else if(root->right==null)
        return root->left;
    else{
        p.data=max
    }
}
```