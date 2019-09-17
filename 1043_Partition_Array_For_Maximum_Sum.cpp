class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N, 0);
        for(int i = 0; i < N; i++) {
            int currMax = 0;
            for(int k = 0; k < K && i - k > -1; k++) {
                currMax = max(currMax, A[i - k]);
                dp[i] = max(dp[i], (i > k ? dp[i - k - 1] : 0) + currMax * (k + 1));
            }
        }
        
        return dp[N - 1];
    }
};