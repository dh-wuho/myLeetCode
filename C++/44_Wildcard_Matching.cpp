class Solution {
public:
    bool isMatch(string s, string p) {
        int sL = s.size();
        int pL = p.size();
        vector<vector<bool> > dp(sL + 1, vector<bool>(pL + 1, false));
        
        dp[0][0] = true;
        for(int i = 0; i < sL + 1; i++) {
            for(int j = 1; j < pL + 1; j++) {
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || (i > 0 && (dp[i - 1][j - 1] || dp[i - 1][j]));
                }
                else {
                    if(p[j - 1] == '?') {
                        dp[i][j] = i > 0 && dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = i > 0 && dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                    }
                }
            }
        }
                
        return dp[sL][pL];
    }
};