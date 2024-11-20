void helper(Node* root, int currentLevel, vector<int> &result){
    if (!root) return;
    if (currentLevel >= result.size()) {
        result.push_back(root->data);
    }
    helper(root->left, currentLevel + 1, result);
    helper(root->right, currentLevel + 1, result);
}

vector<int> leftView(Node* root){
    vector<int> result;
    helper(root, 0, result);
    return result;
}