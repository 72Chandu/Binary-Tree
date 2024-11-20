#include <iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};
// Recursive function to perform postorder traversal on the tree
void postorder(Node* root){
    if (root == nullptr) {// if the current node is empty
        return;
    }
    postorder(root->left);// Traverse the left subtree
    postorder(root->right);// Traverse the right subtree
    cout << root->data << " ";   // Display the data part of the root (or current node)
   
}
// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root){
    if (root == nullptr) {// return if the tree is empty
        return;
    }
    stack<Node*> s;// create an empty stack and push the root node
    s.push(root);
    stack<int> out;// create another stack to store postorder traversa
    while (!s.empty()){// loop till stack is empty
        Node* curr = s.top();  // pop a node from the stack and push the data into the output stack
        s.pop();
        out.push(curr->data);
        if (curr->left) {// push the left and right child of the popped node into the stack 
            s.push(curr->left);
        }
        if (curr->right) {
            s.push(curr->right);
        }
    }
    while (!out.empty()){// print postorder traversal
        cout << out.top() << " ";
        out.pop();
    }
}
int main(){
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    postorder(root);
    //postorderIterative(root);
    return 0;
}

