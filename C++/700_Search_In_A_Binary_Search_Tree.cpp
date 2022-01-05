class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || val == root->val) {
            return root;
        }
        if(val < root->val) {
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root) {
            if(root->val == val) {
                return root;
            }
            if(root->val > val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return root;
    }
};