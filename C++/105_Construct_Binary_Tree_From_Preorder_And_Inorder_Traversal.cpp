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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, int preStart, vector<int>& inorder, int inStart, int inEnd) {
        if(preStart > preorder.size() - 1 || inStart > inEnd) {
            return NULL;
        }
        
        int midIndex = 0;
        for(int i = inStart; i < inEnd + 1; i++) {
            if(preorder[preStart] == inorder[i]) {
                midIndex = i;
            }
        }
        
        TreeNode* node = new TreeNode(preorder[preStart]);
        node->left = helper(preorder, preStart + 1, inorder, inStart, midIndex - 1);
        node->right = helper(preorder, preStart + midIndex - inStart + 1, inorder, midIndex + 1, inEnd);
        
        return node;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) {
            return NULL;
        }
        
        stack<TreeNode* > aStk;
        TreeNode* root = new TreeNode(preorder[0]);
        aStk.push(root);
        int inIndex = 0;
        
        for(int i = 1; i < preorder.size(); i++) {
            TreeNode* curr = aStk.top();
            if(curr->val != inorder[inIndex]) {
                curr->left = new TreeNode(preorder[i]);
                aStk.push(curr->left);
            }
            else {
                while(!aStk.empty() && aStk.top()->val == inorder[inIndex]) {
                    curr = aStk.top();
                    aStk.pop();
                    inIndex++;
                }
                if(inIndex < inorder.size()) {
                    curr->right = new TreeNode(preorder[i]);
                    aStk.push(curr->right);
                }
            }
        }
        
        return root;
    }
};