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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        
        unordered_map<int, vector<int>> indexMap;
        int leftBound = 0;
        int rightBound = 0;
        queue<pair<int, TreeNode*>> q;
        
        q.push(make_pair(0, root));
        
        while(!q.empty()) {
            int tmpIndex = q.front().first;
            TreeNode* tmpNode = q.front().second;
            q.pop();
            leftBound = min(leftBound, tmpIndex);
            rightBound = max(rightBound, tmpIndex);
            
            indexMap[tmpIndex].push_back(tmpNode->val);
            
            if(tmpNode->left) {
                q.push(make_pair(tmpIndex - 1, tmpNode->left));
            }
            if(tmpNode->right) {
                q.push(make_pair(tmpIndex + 1, tmpNode->right));
            }
        }
        
        for(int i = leftBound; i < rightBound + 1; i++) {
            res.push_back(indexMap[i]);
        }
        
        return res;
    }

};