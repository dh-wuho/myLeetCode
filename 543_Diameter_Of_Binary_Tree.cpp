/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/***                                                *
 * 1. DFS                                           *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        
        return diameter;
    }
    
    int helper(TreeNode* root, int& diameter) {
        if(root == NULL) {
            return 0;
        }
        
        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);
        
        diameter = max(diameter, left + right);
        
        return max(left, right) + 1;
    }
};