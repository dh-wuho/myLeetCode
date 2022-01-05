class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        
        for(int i = 1; i < n + 1; i++) {
            int width = books[i - 1][0];
            int height = books[i - 1][1];
            dp[i] = dp[i - 1] + height;
            // new width should less or equal to shelf_width
            for(int j = i - 1; j > 0 && width + books[j - 1][0] <= shelf_width; j--) {
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
                width += books[j - 1][0];
            }
        }
        
        return dp[n];
    }
};