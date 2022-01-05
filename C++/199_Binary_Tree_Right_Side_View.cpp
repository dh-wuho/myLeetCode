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
 * 1. BFS                                           *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        
        queue<TreeNode*> myQ;
        myQ.emplace(root);
        while(!myQ.empty()) {
            int size = myQ.size();
            for(int i = 0; i < size; i++) {
                TreeNode* front = myQ.front();
                myQ.pop();
                if(i == size - 1) {
                    res.push_back(front->val);
                }   
                if(front->left) {
                    myQ.emplace(front->left);
                }
                if(front->right) {
                    myQ.emplace(front->right);
                } 
            }
        }
        
        return res;
    }
};