#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*         
             1              preorder:    1 2 4 5 3 6 7
           /   \            postorder:   4 5 2 6 7 3 1
          2     3           Inorder:     4 2 5 1 6 3 7
         / \   / \          Levelorder:  1 2 3 4 5 6 7
        4  5  6  7
*/

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
}; 

class Tree {
    public:
        Node *root;
        Tree() { root = nullptr; }
        void create_tree();
        int total_nodes(Node* p);
        int total_leaf_nodes(Node* p);
        int height_of_tree(Node* p);
        void preorder_display(Node* p);
        void iterative_preorder_display(Node* p);
        void postorder_display(Node* p);
        void iterative_postorder_display(Node* p);
        void inorder_display(Node* p);
        void iterative_inorder_display(Node* p);
        void levelorder_display(Node* p);
};

void Tree::create_tree() {
    int val;
    queue<Node*> q;

    // Create root node
    root = new Node;
    cout << "Enter root value: ";
    cin >> val;
    root->data = val;
    root->lchild = root->rchild = nullptr;
    // push the address in queue
    q.push(root);

    Node *ptr, *temp;
    while(!q.empty()) {
        ptr = q.front();
        q.pop();
        // Create left child
        cout << "Left child value of " << ptr->data << " (-1 for no child): ";
        cin >> val;
        if(val != -1) {
            temp = new Node {nullptr, val, nullptr};
            // Store the address of left child in lchild of parent node
            ptr->lchild = temp;
            // push the address in queue
            q.push(temp);
        }

        // Create right child
        cout << "Right child value of " << ptr->data << " (-1 for no child): ";
        cin >> val;
        if(val != -1) {
            temp = new Node {nullptr, val, nullptr};
            // Store the address of right child in rchild of parent node
            ptr->rchild = temp;
            // push the address in queue
            q.push(temp);
        }
    }
}

int Tree::total_nodes(Node *root) {
    int left_nodes, right_nodes;
    if(root != nullptr) {
        left_nodes = total_nodes(root->lchild);
        right_nodes = total_nodes(root->rchild);
        return left_nodes + right_nodes + 1;
    }
    return 0;
}

int Tree::total_leaf_nodes(Node *root) {
    int left_nodes, right_nodes;
    if(root != nullptr) {
        left_nodes = total_nodes(root->lchild);
        right_nodes = total_nodes(root->rchild);
        if(left_nodes == 0 && right_nodes == 0)
            return left_nodes + right_nodes + 1;
        else
            return left_nodes + right_nodes;
    }
    return 0;
}

int Tree::height_of_tree(Node *root) {
    int left_edges, right_edges;
    if(root != nullptr) {
        left_edges = height_of_tree(root->lchild);
        right_edges = height_of_tree(root->rchild);
        if(left_edges > right_edges)
            return left_edges + 1;
        else
            return right_edges + 1;
    }
    return 0;
}

void Tree::preorder_display(Node* root) {
    if(root != nullptr) {
        cout << root->data << " ";
        preorder_display(root->lchild);
        preorder_display(root->rchild);
    }
}

void Tree::iterative_preorder_display(Node* root) {
    stack<Node*> st;
    while(root != nullptr || !st.empty()) {
        if(root != nullptr) {
            cout << root->data << " ";
            st.push(root);
            root = root->lchild;
        } else {
            root = st.top();
            st.pop();
            root = root->rchild;
        }
    }
}

void Tree::postorder_display(Node* root) {
    if(root != nullptr) {
        postorder_display(root->lchild);
        postorder_display(root->rchild);
        cout << root->data << " ";
    }
}


void Tree::iterative_postorder_display(Node* root) {
    stack<long int> st;
    long int temp;  // To convert adderss for marking
    while(root != nullptr || !st.empty()) {
        if(root != nullptr) {
            st.push((long int)root);
            root = root->lchild;
        } else {
            temp = st.top();
            st.pop();
            if(temp > 0) {
                // Push it again for printing, and to know which popped address we have
                // to need for printing, we can mark the adress with negative value.
                st.push(-temp);
                root = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << " ";
                root = nullptr;
            }
        }
    }
}

void Tree::inorder_display(Node* root) {
    if(root != nullptr) {
        inorder_display(root->lchild);
        cout << root->data << " ";
        inorder_display(root->rchild);
    }
}

void Tree::iterative_inorder_display(Node* root) {
    stack<Node*> st;
    while(root != nullptr || !st.empty()) {
        if(root != nullptr) {
            st.push(root);
            root = root->lchild;
        } else {
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->rchild;
        }
    }
}

void Tree::levelorder_display(Node *root) {
    queue<Node*> q;
    cout << root->data << " ";
    q.push(root);
    while(!q.empty()) {
        Node* ptr = q.front();
        q.pop();
        if(ptr->lchild != nullptr) {
            cout << ptr->lchild->data << " ";
            q.push(ptr->lchild);
        }
        if(ptr->rchild != nullptr) {
            cout << ptr->rchild->data << " ";
            q.push(ptr->rchild);
        }
    }
}

int main() {
    Tree tree;
    
    tree.create_tree();

    cout << "Total Nodes: " << tree.total_nodes(tree.root) << endl;
    cout << "Total leaf nodes: " << tree.total_leaf_nodes(tree.root) << endl;
    cout << "Height of tree: " << tree.height_of_tree(tree.root) << endl;
    
   cout << "Preorder: " << endl;
   tree.preorder_display(tree.root);
   cout << endl;
   tree.iterative_preorder_display(tree.root);
   cout << endl;
   
   cout << "Postorder: " << endl;
   tree.postorder_display(tree.root);
   cout << endl;
   tree.iterative_postorder_display(tree.root);
   cout << endl;

   cout << "Inorder: ";
   tree.inorder_display(tree.root);
   tree.iterative_inorder_display(tree.root);
   cout << endl;

   cout << "Levelorder: ";
   tree.levelorder_display(tree.root);
   cout << endl;

    return 0;
}
