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
    int closestValue(TreeNode* root, double target) {
        double diff = DBL_MAX;
        int res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(curr || !stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if(diff > abs(curr->val - target)) {
                diff = abs(curr->val - target);
                res = curr->val;
            }
            curr = curr->right;
        }
        
        return res;
    }
};


class Solution {
public:
    int closestValue(TreeNode* root, double target) {        
        int res = root->val;
        if(target < root->val && root->left) {
            int l = closestValue(root->left, target);
            if(abs(res - target) >= abs(l - target)) {
                res = l;
            }
        } 
        else if(target > root->val && root->right) {
            int r = closestValue(root->right, target);
            if(abs(res - target) >= abs(r - target)) {
                res = r;
            }
        }
        return res;
    }
};