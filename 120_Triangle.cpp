/***                                                *
 * 1. DP                                            *                              
 * Time complexity: O(n^2)                          *
 * Space complexity: O(n)                         ***/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        for(int i = triangle.size() - 2; i > -1; i--) {
            for(int j = 0; j < i + 1; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};