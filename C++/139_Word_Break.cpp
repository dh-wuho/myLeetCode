class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int length = s.size();
        vector<bool> dp(length + 1, false);
        dp[0] = true;
        
        for(int i = 1; i < length + 1; i++) {
            for(int j = i - 1; j > -1; j--) {
                if(dict.count(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[length];
    }
};