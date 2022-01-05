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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t2 == NULL) {
            return t1;
        }
        if(t1 == NULL) {
            return t2;
        }
        
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};

/***                                                *
 * 2. Iteration                                     *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) {
            return t2;
        }
        if(t2 == NULL) {
            return t1;
        }
        
        stack<TreeNode*> myStk;
        myStk.emplace(t1);
        myStk.emplace(t2);
        
        while(!myStk.empty()) {
            TreeNode* f2 = myStk.top();
            myStk.pop();
            TreeNode* f1 = myStk.top();
            myStk.pop();
            f1->val += f2->val;
            if(f1->right && f2->right) {
                myStk.emplace(f1->right);
                myStk.emplace(f2->right);
            }
            else {
                if(f1->right == NULL) {
                    f1->right = f2->right;
                }
            }
            if(f1->left && f2->left) {
                myStk.emplace(f1->left);
                myStk.emplace(f2->left);
            }
            else {
                if(f1->left == NULL) {
                    f1->left = f2->left;
                }
            }   
        }
        
        return t1;
    }
};