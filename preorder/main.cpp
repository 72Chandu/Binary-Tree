#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node *left, *right;
    node(int data){
        this->data=data;
        this->left=this->right=this->right=NULL;
    }
};
void preorder(node* root){
    if(root==NULL) return;//if the current node is empty
    cout<<root->data<<" ";
    preorder(root->left);//traverse the left subtree
    preorder(root->right);//traverse the right subtree
}
void preorderIterative(node* root){
    if(root==NULL) return;
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right){// // push the right child of the popped node into the stack
            s.push(curr->right);
        }
        if(curr->left){// push the left child of the popped node into the stack
            s.push(curr->left);
        }
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
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    root->right->left->right = new node(8);
    preorder(root);
    //preorderIterative(root);
}