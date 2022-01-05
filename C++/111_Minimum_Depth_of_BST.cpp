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
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            return 1;
        }
        
        int min_dep = INT_MAX;
        if(root->left) {
            min_dep = min(minDepth(root->left), min_dep);
        }
        
        if(root->right) {
            min_dep = min(minDepth(root->right), min_dep);
        }
        
        return min_dep + 1;
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
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.emplace(root);
        int min_depth = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left == NULL && tmp->right == NULL) {
                    return min_depth;
                }
                if(tmp->left) {
                    q.emplace(tmp->left);
                }
                if(tmp->right) {
                    q.emplace(tmp->right);
                }
            }
            min_depth++;
        }
        
        return min_depth;
    }
};