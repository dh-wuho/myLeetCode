class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target + 1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i < a) break;
                dp[i] += dp[i - a];
                if(dp[i]>INT_MAX)dp[i]%=INT_MAX;
            }
        }
        return dp.back();
    }
};