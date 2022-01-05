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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        }
        
        if(root->left == NULL && root->right == NULL && sum - root->val == 0) {
            return true;
        }
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        }
        stack<TreeNode*> treeStk;
        stack<int> sumStk;
        
        treeStk.emplace(root);
        sumStk.emplace(sum);
        
        while(!treeStk.empty()) {
            TreeNode* curr = treeStk.top();
            treeStk.pop();
            int s = sumStk.top();
            sumStk.pop();
            if(curr->left == NULL && curr->right == NULL && s - curr->val == 0) {
                return true;
            }
            
            if(curr->right) {
                treeStk.emplace(curr->right);
                sumStk.emplace(s - curr->val);
            }
            
            if(curr->left) {
                treeStk.emplace(curr->left);
                sumStk.emplace(s - curr->val);
            }
            
        }
        
        return false;
    }
};