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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        vector<int> oneRes;
        backtrack(root, sum, oneRes, res);
        return res;
    }
    
    void backtrack(TreeNode* root, int sum, vector<int> oneRes, vector<vector<int>>& res) {
        oneRes.push_back(root->val);
        sum  -= root->val;
        if(root->left == NULL && root->right == NULL && sum == 0) {
            res.push_back(oneRes);        
        }
        else {
            if(root->left) {
                backtrack(root->left, sum, oneRes, res);
            }
        
            if(root->right) {
                backtrack(root->right, sum, oneRes, res);
            }
        }
        oneRes.pop_back();
    }
};