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
 * 1. Divide and Conquer                            *                              
 * Time complexity: O(n)                            *
 * Space complexity: worst case O(n), average       *
 * O(log(n))                                      ***/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        res.push_back(root->val);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
};

/***                                                *
 * 2. Iteration                                     *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        
        stack<TreeNode*> stk;
        
        while(!stk.empty() || root) {
            if(root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            else {
                root = stk.top();
                stk.pop();
                root = root->right;
            }
        }
        
        return res;
    }
};

/***                                                *
 * 3. Morris                                        *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        
        while(curr) {
            if(curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                
                if(prev->right == NULL) {
                    res.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        
        traverse(root, res);
        
        return res;
    }
    
    void traverse(TreeNode* root, vector<int>& res) {
        if(root == NULL) {
            return;
        }
        
        res.push_back(root->val);
        traverse(root->left, res);
        traverse(root->right, res);
    }
};