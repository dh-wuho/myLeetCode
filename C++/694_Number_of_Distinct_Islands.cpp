class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        vector<vector<bool> > seen(rows, vector<bool>(cols, false));
        vector<int> oneIsland;
        set<vector<int>> res;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!seen[i][j] && grid[i][j] == 1) {
                    backTrack(grid, i, j, oneIsland, seen, 0);
                    res.emplace(oneIsland);
                    oneIsland.clear();
                }
            }
        }
        
        return res.size();
    }
    
    void backTrack(vector<vector<int>>& grid, int r, int c, vector<int>& oneIsland, vector<vector<bool>>& seen, int dir) {
        if(r > -1 && r < grid.size() && c > -1 && c < grid[0].size() && !seen[r][c] && grid[r][c] == 1) {
            seen[r][c] = true;
            oneIsland.push_back(dir);
            backTrack(grid, r - 1, c, oneIsland, seen, 1);
            backTrack(grid, r + 1, c, oneIsland, seen, 2);
            backTrack(grid, r, c - 1, oneIsland, seen, 3);
            backTrack(grid, r, c + 1, oneIsland, seen, 4);
            oneIsland.push_back(0);
        }
    }
};