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
 * 1. DFS  Recursion                                *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


/***                                                *
 * 2. DFS  Iteration                                *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(n)                         ***/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        if(root == NULL) {
            return maxDepth;
        }
        
        TreeNode* prev = root;
        stack<TreeNode*> path;
        path.emplace(root);
        while(!path.empty()) {
            maxDepth = max((int)path.size(), maxDepth);
            TreeNode* curr = path.top();
            if(curr->left && curr->left != prev && curr->right != prev) {
                path.emplace(curr->left);
            } else {
                if(curr->right && curr->right != prev) {
                    path.emplace(curr->right);
                }
                else {
                    path.pop();
                }
            }
            prev = curr;
        }
        
        return maxDepth;
    }
};