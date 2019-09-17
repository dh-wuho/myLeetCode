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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) {
            return NULL;
        }
        
        int pVal = p->val;
        int qVal = q->val;
        
        while(root != NULL) {
            int currVal = root->val;
            if(currVal > pVal && currVal > qVal) {
                root = root->left;
            }
            else {
                if(currVal < pVal && currVal < qVal) {
                    root = root->right;
                }
                else {
                    break;;
                }
            }
        }
        
        return root;
    }
};