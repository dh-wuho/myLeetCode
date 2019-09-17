class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int maxRes = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxSoFar = max(maxSoFar + nums[i], nums[i]);
            maxRes = max(maxSoFar, maxRes);
        }
        
        return maxRes;
    }
};