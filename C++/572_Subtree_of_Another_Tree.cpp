/***                                                *
 * 1. Traverse                                      *                              
 * Time complexity: O(m * n)                        *
 * Space complexity: O(n)                         ***/

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        
        if(s == NULL || t == NULL) {
            return false;
        }
        
        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isEqual(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        if(s == NULL || t == NULL) {
            return false;
        }
        return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }
};