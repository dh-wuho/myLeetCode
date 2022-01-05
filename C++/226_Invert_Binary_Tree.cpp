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
    TreeNode* invertTree(TreeNode* root) {
        if(root) {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        
        return root;
    }
};

/***                                                *
 * 2. Iteration                                     *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) {
            return NULL;
        }
        
        stack<TreeNode*> myStk;
        myStk.emplace(root);
        while(!myStk.empty()) {
            TreeNode* top = myStk.top();
            myStk.pop();
            swap(top->left, top->right);
            if(top->left) {
                myStk.emplace(top->left);
            }
            if(top->right) {
                myStk.emplace(top->right);
            }
        }
        
        return root;
    }
};