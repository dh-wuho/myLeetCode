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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root->val == key) {
            if(root->left) {
                TreeNode* maxNode = root->left;
                while(maxNode->right) {
                    maxNode = maxNode->right;
                }
                swap(root->val, maxNode->val);
            }
            else {
                TreeNode* rightSubTree = root->right;
                delete root;
                return rightSubTree;
            }
        }
        
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};