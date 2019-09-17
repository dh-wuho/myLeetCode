class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmpres;
        
        search(candidates, target, 0, tmpres, res);
        
        return res;
    }
    
    void search(vector<int>& candidates, int target, int currPos, vector<int>& tmpres, vector<vector<int>>& res) {
       
        if(target == 0) {
            res.push_back(tmpres);
            return;
        }
        
        if(target < 0) {
            return;
        }
        
        for(int i = currPos; i < candidates.size(); i++) {
            tmpres.push_back(candidates[i]);
            search(candidates, target - candidates[i], i, tmpres, res);
            tmpres.pop_back();
        }
       
    }
};