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
 * Space complexity: O(n)                         ***/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        helper(root, res);
        
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& res) {
        if(root == NULL) {
            return;
        }
        
        helper(root->left, res);
        helper(root->right, res);
        res.push_back(root->val);
    }
};

/***                                                *
 * 2. Iteration                                     *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        stack<TreeNode*> myStack;
        TreeNode* last = NULL;
        
        while(root || !myStack.empty()) {
            if(root) {
                myStack.push(root);
                root = root->left;
            }
            else {
                TreeNode* top = myStack.top();
                if(top->right && top->right != last) {
                    root = top->right;
                }
                else {
                    res.push_back(top->val);
                    myStack.pop();
                    last = top;
                }
                
            }
        }
        
        return res;
    }
};


/***                                                *
 * 3. Divide and Conquer                            *                              
 * Time complexity: O(n)                            *
 * Space complexity: worst case O(n), average       *
 * O(log(n))                                      ***/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
        
        return res;
    }
};

/***                                                *
 * 4. Morris                                        *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        
        while(curr) {      
            if(curr->right) {
                prev = curr->right;
                while(prev->left && prev->left != curr) {
                    prev = prev->left;
                }
                if(prev->left) {
                    prev->left = NULL;
                    curr = curr->left;
                }
                else {
                    res.push_back(curr->val);
                    prev->left = curr;
                    curr = curr->right;
                }
            }
            else {
                res.push_back(curr->val);
                curr = curr->left;
            }
        }
        
        return vector<int>(res.rbegin(), res.rend());
    }
};