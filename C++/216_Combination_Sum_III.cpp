class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmpRes;
        
        search(0, k, n, 1, tmpRes, res);
        
        return res;
    }
    
    void search(int depth, int k, int n, int currPos, vector<int>& tmpRes, vector<vector<int>>& res) {
        if(n < 0 || depth > k) {
            return;
        }
        
        
        if(n == 0 && depth == k) {
            res.push_back(tmpRes);
            return;
        }
        
        for(int i = currPos; i < 10; i++) {
            tmpRes.push_back(i);
            search(depth + 1, k, n - i, i + 1, tmpRes, res);
            tmpRes.pop_back();
        }
    }
};