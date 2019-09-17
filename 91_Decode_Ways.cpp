class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        if(length == 0 || s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(length + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < length + 1; i++) {
            if(s[i - 1] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i - 1];
            }
            if(i > 1 && (s[i - 2] == '1' || 
                         (s[i - 2] == '2' && s[i - 1] <= '6' && s[i - 1] >= 1))) {
                // dp[i] = dp[i - 1] + dp[i - 2].
                // here dp[i] = dp[i - 1]
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[length];
    }
};