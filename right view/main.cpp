void helper(Node* root, int currentLevel, vector<int> &result){
    if (!root) return;
    if (currentLevel >= result.size()) {
        result.push_back(root->data);
    }
    helper(root->right, currentLevel + 1, result);
    helper(root->left, currentLevel + 1, result);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root){
    vector<int> result;
    helper(root, 0, result);
    return result;
    }