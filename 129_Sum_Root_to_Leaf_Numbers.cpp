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
    int sumNumbers(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        stack<TreeNode*> stk;
        int res = 0;
        stk.push(root);
        
        while(!stk.empty()) {
            TreeNode* tmp = stk.top();
            stk.pop();
            if(tmp->left == NULL && tmp->right == NULL) {
                res += tmp->val;
            }
            if(tmp->right) {
                tmp->right->val += tmp->val * 10;
                stk.push(tmp->right);    
            }
            if(tmp->left) {
                tmp->left->val += tmp->val * 10;
                stk.push(tmp->left);   
            }
        }
        
        return res;
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
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
    
    int DFS(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            return sum * 10 + root->val;
        }
        sum = sum * 10 + root->val;
        return DFS(root->left, sum) + DFS(root->right, sum);
    }
};