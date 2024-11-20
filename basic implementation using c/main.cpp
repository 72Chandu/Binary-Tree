#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node*left;
    node*right;
    node(int data){
        val=data;
        left=right=NULL;
    }
};
int main(){
    node*root=new node(2);
    root->left=new node(3);
    root->right=new node(4);
    cout<<"root-"<<root->val<<endl;
    cout<<"left child-"<<root->left->val<<endl;
    cout<<"right child-"<<root->right->val<<endl;
}