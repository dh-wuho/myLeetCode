/***                                                *
 * 1. Recursion                                     *                              
 * Time complexity: O(n)                            *
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        
        if(p == NULL || q == NULL) {
            return false;
        }
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/***                                                *
 * 2. Iteration                                     *                              
 * Time complexity: O(n)                            *
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        stk.emplace(p);
        stk.emplace(q);
        
        while(!stk.empty()) {
            TreeNode* currQ = stk.top();
            stk.pop();
            TreeNode* currP = stk.top();
            stk.pop();
            if(currQ == NULL && currP == NULL) {
                continue;
            }
            if(currQ && currP) {
                if(currQ->val != currP->val) {
                    return false;
                }
                stk.emplace(currP->left);
                stk.emplace(currQ->left);
                stk.emplace(currP->right);
                stk.emplace(currQ->right);
            }
            else {
                return false;
            }
        }
        return true;
    }
};