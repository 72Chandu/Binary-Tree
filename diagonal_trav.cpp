#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left, *right;
    node(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

void diagonalRecur(node* root, int level,unordered_map<int,vector<int>>&level_data){
    if(root==nullptr) return;
    level_data[level].push_back(root->data);
    diagonalRecur(root->left,level+1,level_data);//traverse left subtree
    diagonalRecur(root->right,level,level_data);//traverse right subtree
}
vector<int> diagonalTrav(node *root){
    vector<int>ans;
    unordered_map<int,vector<int>>level_data;//level,respective element on that level
    diagonalRecur(root,0,level_data);
    int level=0;
    while(level_data.find(level)!=level_data.end()){
        vector<int>v=level_data[level];
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]);
        }
        level++;
    }
    return ans;
}
void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    
    // Create a hard coded tree
    //         8
    //       /   \
    //     3      10
    //    /      /  \
    //   1      6    14
    //         / \   /
    //        4   7 13

    node *root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->right->left = new node(6);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    root->right->left->left = new node(4);
    root->right->left->right = new node(7);

    vector<int>ans=diagonalTrav(root);
    print(ans);
}

