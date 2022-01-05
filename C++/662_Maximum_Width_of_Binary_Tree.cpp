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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        long maxWidth = 0;

        queue<pair<TreeNode*, int> > myq;
            
        myq.push({root, 0});
        while(!myq.empty()) {
            long left = myq.front().second;
            long right = left;
            int currWidth = myq.size();
            
            for(int i = 0; i < currWidth; i++) {
                TreeNode* tmp = myq.front().first;
                right = myq.front().second;
                myq.pop();
                if(tmp->left) {
                    myq.push({tmp->left, 2 * right});    
                }
                if(tmp->right) {
                    myq.push({tmp->right, 2 * right + 1});
                }
            }           
            maxWidth = max(maxWidth, right - left + 1);
        }
        
        return maxWidth;
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


// overflow problem
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> start;
        int res;
        dfs(root, start, 0, 1, res);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& start, int curr, int h, int& res) {
        if(root == NULL) {
            return;
        }
        
        if(start.size() < h) {
            start.push_back(curr);
        }
        
        res = max(res, curr - start[h - 1] + 1);
        
        dfs(root->left, start, curr * 2, h + 1, res);
        dfs(root->right, start, curr * 2 + 1, h + 1, res);
    }
};