//987. Vertical Order Traversal of a Binary Tree
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node* left, *right;
    node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void verticalRecur(node* root, int hd, int depth, map<int, vector<pair<int, int>>>& m) {
    if (root == nullptr) return;

    // Store the current value with its depth at the corresponding horizontal distance
    m[hd].push_back({depth, root->data});

    // Traverse the left and right subtrees
    verticalRecur(root->left, hd - 1, depth + 1, m);
    verticalRecur(root->right, hd + 1, depth + 1, m);
}

vector<vector<int>> verticalTrav(node* root) {
    vector<vector<int>> ans;
    map<int, vector<pair<int, int>>> m; // Use map to maintain sorted order of horizontal distances
    verticalRecur(root, 0, 0, m);

    // Traverse the map to collect nodes in vertical order
    for (auto it = m.begin(); it != m.end(); ++it) {
        // Sort nodes at the same horizontal distance by depth, and then by value if depths are the same
        sort(it->second.begin(), it->second.end());
        vector<int> column;
        for (auto& p : it->second) {
            column.push_back(p.second);
        }
        ans.push_back(column);
    }
    return ans;
}

void print(const vector<vector<int>>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << "[";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j != v[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Create a hardcoded tree
    //         1
    //       /   \
    //     2       3
    //    / \     / \
    //   4   6   5   7

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(7);

    vector<vector<int>> ans = verticalTrav(root);
    print(ans);

    return 0;
}
