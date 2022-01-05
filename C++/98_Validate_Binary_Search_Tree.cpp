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
 * 1. Iteration Inorder Traversal                   *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> myS;
        TreeNode* prevNode = NULL;
        
        while(!myS.empty() || root) {
            if(root) {
                myS.emplace(root);
                root = root->left;
            }    
            else {
                root = myS.top();
                myS.pop();
                if(prevNode && root->val <= prevNode->val) {
                    return false;
                }
                prevNode = root;
                root = root->right;
            }
        }
        
        return true;
    }
};

/***                                                *
 * 2. Divide and Conquer                            *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    bool isValidBST(TreeNode* root) { 
        return helper(root, NULL, NULL);
    }
    
    bool helper(TreeNode* root, TreeNode* leftBound, TreeNode* rightBound) {
        if(root == NULL) {
            return true;
        }
        if(leftBound != NULL && leftBound->val >= root->val) {
            return false;
        }
        if(rightBound != NULL && rightBound->val <= root->val) {
            return false;
        }
        
        
        bool left = helper(root->left, leftBound, root);
        bool right = helper(root->right, root, rightBound);
        
        if(left && right) {
            return true;
        }
        
        return false;
    }
};