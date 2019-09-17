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
 * 1. Traversal                                     *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n),                        ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
    
    void traverse(TreeNode* root, vector<int>& res) {
        if(root == NULL) {
            return;
        }
        
        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }
};

/***                                                *
 * 2. Divide and Conquer                            *                              
 * Time complexity: O(n)                            *
 * Space complexity: worst case O(n), average       *
 * O(log(n))                                      ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        
        res.insert(res.end(), left.begin(), left.end());
        res.push_back(root->val);
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
};

/***                                                *
 * 3. Iteration                                     *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> myStack;
        
        while(!myStack.empty() || root) {
            if(root) {
                myStack.push(root);
                root = root->left;
            }
            else {
                root = myStack.top();
                myStack.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        
        return res;
    }
};

/***                                                *
 * 4. Morris                                        *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* prev;
        
        while(curr) {
            if(!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                // change binary tree
                if(prev->right == NULL) {  
                    prev->right = curr;
                    curr = curr->left;
                }
                // restore binary tree
                else {              
                    prev->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return res;
    }
};