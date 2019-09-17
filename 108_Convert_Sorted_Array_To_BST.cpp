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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generateBST(nums, 0, (int)nums.size() - 1);
    }
    
    TreeNode* generateBST(vector<int>& nums, int start, int end) {
        if(start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = generateBST(nums, start, mid - 1);
        curr->right = generateBST(nums, mid + 1, end);
        return curr;
    }
};