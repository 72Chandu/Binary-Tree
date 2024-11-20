#include <iostream>
#include<stack>
using namespace std;
struct Node{// Data structure to store a binary tree node
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};
void inorder(Node* root){// Recursive function to perform inorder traversal on the tree
    if (root == nullptr) {  // return if the current node is empty
        return;
    }
    inorder(root->left); // Traverse the left subtree
    cout << root->data << " ";// Display the data part of the root (or current node)
    inorder(root->right);// Traverse the right subtree
}
void inorderIterative(Node* root){// Iterative function to perform inorder traversal on the tree
    stack<Node*> stack;// create an empty stack
    Node* curr = root;// start from the root node (set current node to the root node)
    while (!stack.empty() || curr != nullptr){// if the current node is null and the stack is also empty, we are done
        if (curr != nullptr){// if the current node exists, push it into the stack (defer it) and move to its left child
            stack.push(curr);
            curr = curr->left;
        }
        else { // otherwise, if the current node is null, pop an element from the stack, print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}
int main(){
    /*
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
    inorder(root);
    cout<<"\n";
    inorderIterative(root);
    return 0;
}


