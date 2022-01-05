class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n == 0 || k == 0) {
            return res;
        }
        vector<int> curr;
        dfs(n, 1, k, curr, res);
        
        return res;
    }
    
    void dfs(int n, int ith, int k, vector<int>& curr, vector<vector<int>>& res) {
        if(curr.size() == k) {
            res.push_back(curr);
            return;
        }
        
        for(int i = ith; i < n + 1; i++) {
            curr.push_back(i);
            dfs(n, i + 1, k, curr, res);
            curr.pop_back();
        }
    }
};