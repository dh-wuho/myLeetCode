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
 * 1. Recursion                                     *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) {
            return res;
        }
        helper(root, res, "");
        return res;
    }
    void helper(TreeNode* root, vector<string>& res, string oneRes) {
        oneRes += to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            res.push_back(oneRes);
            return;
        }
        
        oneRes += "->";
        if(root->left) {
            helper(root->left, res, oneRes);
        }
        if(root->right) {
            helper(root->right, res, oneRes);
        }
    }
};