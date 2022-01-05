class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }        
        if(s1 == s2) {
            return true;
        }
        
        unordered_map<int, int> table;
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            table[s1[i] - 'a']++;
            table[s2[i] - 'a']--;
        }
        
        unordered_map<int, int>::iterator it;
        for(it = table.begin(); it != table.end(); it++) {
            if(it->second != 0) {
                return false;
            }
        }
        
        for(int i = 1; i < n; i++) {
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) || 
               (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i)))) {
                return true;
            }
        }
        
        return false;
    }
};

/* 
 * 维护量res[i][j][n]，其中i是s1的起始字符，j是s2的起始字符，而n是当前的 
 * 字符串长度，res[i][j][len]表示的是以i和j分别为s1和s2起点的长度为len的
 * 字符串是不是互为scramble。
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }        
        if(s1 == s2) {
            return true;
        }
        
        int n = s1.size();
        vector<vector<vector<bool> > > dp(n, vector<vector<bool> >(n, vector<bool>(n + 1, false)));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s1[i] == s2[j]) {
                    dp[i][j][1] = true;
                }
            }
        }
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                for(int j = 0; j <= n - len; j++) {
                    // k is range of len, from 1 to len
                    for(int k = 1; k < len; k++) {
                        if((dp[i][j][k] && dp[i + k][j + k][len - k]) || 
                           (dp[i][j + len - k][k] && dp[i + k][j][len - k])) {
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        
        return dp[0][0][n];
    }
};