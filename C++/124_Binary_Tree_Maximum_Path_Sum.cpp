/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        sumHelper(root, maxSum);
        return maxSum;
    }
    
    int sumHelper(TreeNode* root, int& maxSum) {
        if(root == NULL) {
            return INT_MIN;
        }
        
        int left = sumHelper(root->left, maxSum);
        int right = sumHelper(root->right, maxSum);
        
        left = max(left, 0);
        right = max(right, 0);
        maxSum = max(maxSum, left + right + root->val);
        
        return max(left, right) + root->val;
    }
};