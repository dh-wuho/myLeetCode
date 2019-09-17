/***                                                *
 * 1. method                                        *                              
 * Time complexity: O(nlogn)                        *
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
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        vector<TreeNode*> nodes;
        inorder(root, arr, nodes);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < nodes.size(); i++) {
            nodes[i]->val = arr[i];
        }
    }
    
    void inorder(TreeNode* root, vector<int>& arr, vector<TreeNode*>& nodes) {
        if(root == NULL) {
            return;
        }
        
        inorder(root->left, arr, nodes);
        arr.push_back(root->val);
        nodes.push_back(root);
        inorder(root->right, arr, nodes);
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
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev;
        TreeNode* parent = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        
        while(curr) {
            if(curr->left == NULL) {
                if(parent && parent->val > curr->val) {
                    if(first == NULL) {
                        first = parent;
                    }
                    second = curr;
                }
                parent = curr;
                curr = curr->right;
            }
            else {
                prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {  // left part is not traversed
                    prev->right = curr;
                    curr = curr->left;
                }
                else {                     // left part is traversed
                    prev->right = NULL;
                    if(parent && parent->val > curr->val) {
                        if(first == NULL) {
                            first = parent;
                        }
                        second = curr;
                    }
                    parent = curr;
                    curr = curr->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};