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
 * 1. DFS Recursion                                 *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;  
        dfs(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& res, int level) {
        if(root == NULL) {
            return;
        }
        
        if(res.size() == level) {
            res.push_back(vector<int>());
        }
        
        res[level].push_back(root->val);
        dfs(root->left, res, level + 1);
        dfs(root->right, res, level + 1);
    }
};