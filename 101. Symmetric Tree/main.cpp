//https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
    bool checksym(TreeNode* n1,TreeNode* n2){
        if(n1==NULL && n2==NULL) return true;
        if(n1==NULL || n2==NULL) return false;
        if(n1->val != n2->val) return false;

        bool res1=checksym(n1->left, n2->right);
        bool res2=checksym(n1->right, n2->left);
        
        if(res1==true && res2==true) return true;
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return checksym(root->left, root->right);
    }
};