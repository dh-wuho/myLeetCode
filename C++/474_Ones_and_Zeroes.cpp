class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // m - 0, n - 1
        for(string s : strs) {
            int n0 = 0;
            int n1 = 0;
            for(char c : s) {
                if(c == '0') {
                    n0++;
                }
                else {
                    n1++;
                }
            }
            
            for(int i = m; i >= n0; i--) {
                for(int j = n; j >= n1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - n0][j - n1] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};