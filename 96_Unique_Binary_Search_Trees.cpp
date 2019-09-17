class Solution {
public:
    int numTrees(int n) {
        // dp[i] is the number of Unique Binary Trees with i nodes.
        // 卡塔兰数 Catalan Numbe
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i < n + 1; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        
        return dp[n];
    }
};


class Solution {
public:
    int numTrees(int n) {
        // 卡塔兰数 Catalan Numbe
        // recursive formula
        // C_(n+1) = 2(2n + 1)/(n + 2) * C_n
        long C = 1;
        for(int i = 0; i < n; i++) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        
        return (int)C;
    }
};