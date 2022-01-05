class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmpRes;
        sort(candidates.begin(), candidates.end());
        combinationHelper(candidates, target, 0, tmpRes, res);
        return res;
    }
    
    void combinationHelper(vector<int>& candidates, int target, int start, vector<int> tmpRes, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(tmpRes);
            return;
        }
        if(target < 0 || start == candidates.size()) {
            return;
        }
        
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            tmpRes.push_back(candidates[i]);
            combinationHelper(candidates, target - candidates[i], i + 1, tmpRes, res);
            tmpRes.pop_back();
        }
    }
};