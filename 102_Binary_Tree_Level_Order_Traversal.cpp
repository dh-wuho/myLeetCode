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
 * 1. Traverse by using one Queue                   *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        
        queue<TreeNode*> myQ;
        myQ.emplace(root);
        while(!myQ.empty()) {
            int size = myQ.size();
            vector<int> oneRes;
            for(int i = 0; i < size; i++) {
                TreeNode* front = myQ.front();
                oneRes.push_back(front->val);
                myQ.pop();
                if(front->left) {
                    myQ.emplace(front->left);
                }
                if(front->right) {
                    myQ.emplace(front->right);
                }
            }
            res.push_back(oneRes);
        }
        
        return res;
    }
};