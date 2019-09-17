class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) {
            return s.empty();
        }
        
        if(p.size() == 1) {
            return s.size() == 1 && (p[0] == s[0] || p[0] == '.');
        }
        
        if(p[1] != '*') {
            if(s.empty()) {
                return false;
            }
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if(isMatch(s, p.substr(2))) {
                return true;
            }
            s = s.substr(1);
        }
        
        return isMatch(s, p.substr(2));
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        int sL = s.size();
        int pL = p.size();
        
        vector<vector<bool> > dp(sL + 1, vector<bool>(pL + 1, false));
        
        dp[0][0] = true;
        for(int i = 0; i < sL + 1; i++) {
            for(int j = 1; j < pL + 1; j++) {
                if(j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || (p[j - 1] == '.'));
                }
            }
        }
        
        return dp[sL][pL];
    }
};