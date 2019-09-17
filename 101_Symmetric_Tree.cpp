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
    bool isSymmetric(TreeNode* root) {
        return cmpLR(root, root);
    }
    
    bool cmpLR(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        
        if(r1 == NULL || r2 == NULL) {
            return false;
        }
        
        return (r1->val == r2->val) && cmpLR(r1->left, r2->right) && cmpLR(r1->right, r2->left);
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> myQ;
        myQ.push(root);
        myQ.push(root);
        
        while(!myQ.empty()) {
            TreeNode* r1 = myQ.front();
            myQ.pop();
            TreeNode* r2 = myQ.front();
            myQ.pop();
            if(r1 == NULL && r2 == NULL) {
                continue;
            }
            if(r1 == NULL || r2 == NULL) {
                return false;
            }
            if(r1->val != r2->val) {
                return false;
            }
            myQ.push(r1->left);
            myQ.push(r2->right);
            myQ.push(r1->right);
            myQ.push(r2->left);
        }
         
        return true;
    }   
};