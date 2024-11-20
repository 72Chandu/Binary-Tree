//https://leetcode.com/problems/invert-binary-tree/description/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
/*

        4
       / \
      2   7
     / \ / \
    1  3 6  9
curr node=4, l=2 r=7 swap

        4
       / \
      7   2
     / \ / \
    6  9 1  3
call left sub tree curr node=7, l=6, r=9 swap

        4
       / \
      7   2
     / \ / \
    9  6 1  3
call left sub tree curr node=9  l=null, r=null
call right sub tree curr node=6  l=null, r=null return to privious call
Back to Node 7  Both left and right subtrees of 7 are inverted. Return to previous call.

call right sub tree curr node=2  l=1, r=3 swap
        4
       / \
      7   2
     / \ / \
    9  6 3  1
call left sub tree curr node=23 l=null, r=null , Return to previous call.
call right sub tree curr node=1, l=null, r=null, Return to previous call.
Back to Node 2 Both left and right subtrees of 2 are inverted. Return to previous call.
Back to Node 4 Both left and right subtrees of 4 are inverted. The final tree is:
        4
       / \
      7   2
     / \ / \
    9  6 3  1

*/