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
    bool isBalanced(TreeNode* root) {
        if(maxDepth(root) != -1) {
            return true;
        }
        
        return false;
    }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        if(left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        
        return max(left, right) + 1;
    }
};