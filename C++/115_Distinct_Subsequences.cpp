class Solution {
public:
    int numDistinct(string s, string t) {
        int sL = s.size();
        int tL = t.size();
        
        vector<vector<long>> dp(sL + 1, vector<long>(tL + 1, 0));
        for(int i = 0; i < sL + 1; i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < sL + 1; i++) {
            for(int j = 1; j < tL + 1; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[sL][tL];
    }
};