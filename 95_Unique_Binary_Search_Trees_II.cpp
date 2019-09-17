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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) {
            return res;
        }
        return divideConquer(1, n);
    }
    
    vector<TreeNode*> divideConquer(int start, int end) {
        if(start > end) {
            return {NULL};
        }
        vector<TreeNode*> res;
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> left = divideConquer(start, i - 1);
            vector<TreeNode*> right = divideConquer(i + 1, end);
            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        
        return res;
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) {
            return res;
        }
        vector<vector<vector<TreeNode*>>> mem(n, vector<vector<TreeNode*>>(n));
        return divideConquer(1, n, mem);
    }
    
    vector<TreeNode*> divideConquer(int start, int end, vector<vector<vector<TreeNode*>>>& mem) {
        if(start > end) {
            return {NULL};
        }
        if(!mem[start - 1][end - 1].empty()) {
            return mem[start - 1][end - 1];
        }
        vector<TreeNode*> res;
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> left = divideConquer(start, i - 1, mem);
            vector<TreeNode*> right = divideConquer(i + 1, end, mem);
            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        mem[start - 1][end - 1] = res;
        return res;
    }
};


// https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31516/Share-a-C%2B%2B-DP-solution-with-O(1)-space