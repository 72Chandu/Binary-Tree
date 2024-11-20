//https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1;
        vector<long long> each_level_sum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size(); //size is changing 
            long long sum=0;
            for(int i=0;i<size;i++){  //level order traversal 
                TreeNode* node=q.front();
                q.pop();
                sum +=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            each_level_sum.push_back(sum);//storing each level sum 
        }
        sort(each_level_sum.begin(), each_level_sum.end(), greater<long long>());
        if(k>each_level_sum.size()) return -1;
        return each_level_sum[k-1];
    }
};
//TC=O(n + m log m), where m <= n.  , m=no of level,  n=no of node
//SC=O(m + n)
/* root = [5,8,9,2,1,3,7,4,6], k = 2
        5
       / \
      8   9
     / \ / \
    2  1 3  7
   / \
  4   6

Initially, we add the root node (5) to the queue.    Queue: [5]   Level sums: [] (Empty initially)
Level 1 sum: 5
Add its children (8 and 9) to the queue.  [8, 9]
Level sums: [5]

Level 2:  We process both nodes 8 and 9:    sum: 8 + 9 = 17
Add their children to the queue: for node 8-> 2, 1; 9->3,7.    [2, 1, 3, 7]
Level sums: [5, 17]

Level 3:   sum: 2 + 1 + 3 + 7 = 13
Add their children to the queue: for node 2, add 4,6 (no children for 1, 3, and 7).     [4, 6]
Level sums: [5, 17, 13]

Level 4:   sum: 4 + 6 = 10     No children to add for 4 and 6.
Queue after Level 4: [] (empty, traversal complete)
Level sums: [5, 17, 13, 10]
*/