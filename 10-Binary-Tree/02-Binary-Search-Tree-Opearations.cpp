#include <iostream>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
}; 

class Binary_Search_Tree {
    public:
        Node *root;
        Binary_Search_Tree() { root = nullptr; }
        Node* recursive_search(Node* root, int key);
        Node* iterative_search(Node* root, int key);
        Node* recursive_insert(Node* root, int value);
        Node* iterative_insert(Node* root, int value);
        void inorder_display(Node* root);
};

Node* Binary_Search_Tree::recursive_search(Node *root, int key) {
    if(root == nullptr)
        return nullptr;
    if(root->data == key)
        return root;
    else if(key < root->data)
        return recursive_search(root->lchild, key);
    else    // key > root->data
        return recursive_search(root->rchild, key);
}

Node* Binary_Search_Tree::iterative_search(Node* root, int key) {
    while(root != nullptr) {
        if(root->data == key)
            return root;
        else if(key < root->data)
            root = root->lchild;
        else
            root = root->rchild;
    }
    return nullptr;
}

Node* Binary_Search_Tree::iterative_insert(Node* root, int value) {
    if(root == nullptr)
        return new Node{nullptr, value, nullptr};

    Node* current = root;
    Node* parent = nullptr;

    while(current != nullptr) {
        parent = current;

        if(current->data == value)
            return root;    // Duplicate, do not insert
        else if(value < current->data)
            current = current->lchild;
        else 
            current = current->rchild;
    }

    Node* temp = new Node{nullptr, value, nullptr};

    // If key is smaller, make it left child, else right child
    if(parent->data > value)
        parent->lchild = temp;
    else
        parent->rchild = temp;

    return root;
}

Node* Binary_Search_Tree::recursive_insert(Node* root, int value) {
    if(root == nullptr)
        return new Node{nullptr, value, nullptr};
    if(value < root->data)
        root->lchild = recursive_insert(root->lchild, value);
    else if(value > root->data)
        root->rchild = recursive_insert(root->rchild, value);
    // else duplicate: do nothing
    
    return root;
}

// Inorder display shows binary tree in sorted order
void Binary_Search_Tree::inorder_display(Node* root) {
    if(root != nullptr) {
        inorder_display(root->lchild);
        cout << root->data << " ";
        inorder_display(root->rchild);
    }
}

int main() {
    Binary_Search_Tree bst;
    bst.root = bst.iterative_insert(bst.root, 10);
    bst.root = bst.iterative_insert(bst.root, 5);
    bst.root = bst.iterative_insert(bst.root, 20);
    bst.root = bst.iterative_insert(bst.root, 8);
    bst.root = bst.iterative_insert(bst.root, 30);

    bst.inorder_display(bst.root);
    cout << endl;

    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    Node* search = bst.iterative_search(bst.root, key);
    if(search != nullptr)
        cout << key << " is found" << endl;
    else
        cout << "key is not found." << endl;

    return 0;
}
