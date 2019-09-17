/***                                                *
 * 1. Recursion                                     *                              
 * Time complexity: O(2^n)                          *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subset;
        
        sort(nums.begin(), nums.end());
        subsetsHelper(nums, 0, subset, res);
        
        return res;
    }
    
    void subsetsHelper(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);
        for(int i = start; i < nums.size(); i++) {
            if(i == start || nums[i] != nums[i - 1]) {
                subset.push_back(nums[i]);
                subsetsHelper(nums, i + 1, subset, res);
                subset.pop_back();
            }
            
        }
    }
};

/***                                                *
 * 2. Iteration                                     *                              
 * Time complexity: O(2^n)                          *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res(1, vector<int>());
        int beginFrom;
        int size;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                beginFrom = size;
            }
            else {
                beginFrom = 0;
            }
            size = res.size();
            for(int j = beginFrom; j < size; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        
        return res;
    }
};