class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if(length < 2) {
            return length;
        }
        vector<int> dp(length, 1);
        int res = 1;
        
        dp[0] = 1;
        for(int i = 1; i < length; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(dp[i], res);
        }
        
        return res;
    }
};