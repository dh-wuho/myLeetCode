/***                                                *
 * 1. method                                        *                              
 * Time complexity:                                 *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permuteHelper(nums, 0, res);
        return res;
    }
    
    void permuteHelper(vector<int> nums, int start, vector<vector<int>>& res) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            if(i != start && nums[start] == nums[i]) {
                continue;
            }
            swap(nums[start], nums[i]);
            permuteHelper(nums, start + 1, res);
        }
    }
    
};