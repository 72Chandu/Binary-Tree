//https://leetcode.com/problems/validate-binary-search-tree/description/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to validate the BST
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        // Base case: If we reach a null node, it's valid
        if (!root) return true;

        // If the current node's value violates the range, return false
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Recursively check the left and right subtrees
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }

    // Public function to initiate the validation
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// Example usage
int main() {
    Solution solution;

    // Example 1: Tree is a valid BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "Example 1: " << (solution.isValidBST(root1) ? "true" : "false") << endl;

    // Example 2: Tree is not a valid BST
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "Example 2: " << (solution.isValidBST(root2) ? "true" : "false") << endl;

    return 0;
}
