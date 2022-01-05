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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
    
    TreeNode* helper(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd) {
        if(preStart > preEnd || postStart > postEnd) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[preStart]);
        if(preStart == preEnd) {
            return root;
        }
        
        
        int post_leftEnd = 0;
        for(int i = postStart; i < postEnd + 1; i++) {
            if(post[i] == pre[preStart + 1]) {
                post_leftEnd = i;
            }
        }
        int pre_leftStart = preStart + 1;
        int pre_leftEnd = pre_leftStart + post_leftEnd - postStart;
        root->left = helper(pre, pre_leftStart, pre_leftEnd, post, postStart, post_leftEnd);
        root->right = helper(pre, pre_leftEnd + 1, preEnd, post, post_leftEnd + 1, postEnd - 1);
        return root;
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.empty()) {
            return NULL;
        }  
        stack<TreeNode*> aStk;
        TreeNode* root = new TreeNode(pre[0]);
        aStk.emplace(root);
        int postIndex = 0;
        
        for(int i = 1; i < pre.size(); i++) {
            TreeNode* newNode = new TreeNode(pre[i]);
            while(aStk.top()->val == post[postIndex]) {
                aStk.pop();
                postIndex++;
            }
            if(aStk.top()->left == NULL) {
                aStk.top()->left = newNode;
            }
            else {
                aStk.top()->right = newNode;
            }
            aStk.emplace(newNode);
        }
        
        return root;
    }
};