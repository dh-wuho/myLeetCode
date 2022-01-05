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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        
        if(root) {
            res.push_back(root->val);
        }
        else {
            return res;
        }
        
        helper(root->left, true, false, res);
        helper(root->right, false, true, res);
        
        return res;
    }
    
    void helper(TreeNode* node, bool lb, bool rb, vector<int>& res) {
        if(node == NULL) {
            return;
        }
        if(node->left == NULL && node->right == NULL) {
            res.push_back(node->val);
            return;
        }
        if(lb) {
            res.push_back(node->val);
        } 
        
        helper(node->left, lb, rb && node->right == NULL, res);
        helper(node->right, lb && node->left == NULL , rb, res);
        
        if(rb) {
            res.push_back(node->val);
        }
        
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        TreeNode* leaf = root;
        
        if(root->left || root->right) {
            res.push_back(root->val);
        }
        
        while(l && (l->left || l->right)) {
            res.push_back(l->val);
            if(l->left) {
                l = l->left;
            }
            else {
                l = l->right;
            }
        }
        
        stack<TreeNode*> stk;
        while(!stk.empty() || leaf) {
            if(leaf) {
                stk.push(leaf);
                if(leaf->left == NULL && leaf->right == NULL) {
                    res.push_back(leaf->val);
                }
                leaf = leaf->left;
            }
            else {
                leaf = stk.top();
                stk.pop();
                leaf = leaf->right;
            }
        }
        
        vector<int> rRes;
        while(r && (r->left || r->right)) {
            rRes.push_back(r->val);
            if(r->right) {
                r = r->right;
            }
            else {
                r = r->left;
            }
        }
        
        res.insert(res.end(), rRes.rbegin(), rRes.rend());
        
        return res;
    }
    
};