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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postEnd) {
        if(inStart > inEnd || 0 > postEnd) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int midIndex = 0;
        for(int i = inStart; i < inEnd + 1; i++) {
            if(inorder[i] == postorder[postEnd]) {
                midIndex = i;
            } 
        }
        
        root->left = helper(inorder, inStart, midIndex - 1, postorder, postEnd - 1 - inEnd + midIndex);
        root->right = helper(inorder, midIndex + 1, inEnd, postorder, postEnd - 1);
        return root;
    }
};