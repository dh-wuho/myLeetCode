/***                                                 *
 * 1. DP                                             *                              
 * Time complexity: O(mn)                            *
 * Space complexity: O(mn)                         ***/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int columns = obstacleGrid[0].size();
        long dp[rows][columns];
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if(i == 0) {
                    dp[i][j] = 1 * dp[i][j - 1];
                }
                else if(j == 0) {
                    dp[i][j] = 1 * dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[rows - 1][columns - 1];
    }  
};