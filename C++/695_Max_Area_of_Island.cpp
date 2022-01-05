class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int h = grid.size();
        if(h == 0) {
            return res;
        }
        int w = grid[0].size();
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(grid[i][j]) {
                    int curr = 0;
                    dfs(grid, i, j, curr, res);
                }
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c, int& curr, int& res) {
        if(r < 0 || r + 1 > grid.size() || c < 0 || c + 1 > grid[0].size() || grid[r][c] == 0) {
            return;
        }
        
        curr++;
        res = max(res, curr);
        grid[r][c] = 0;
        dfs(grid, r - 1, c, curr, res);
        dfs(grid, r, c + 1, curr, res);
        dfs(grid, r + 1, c, curr, res);
        dfs(grid, r, c - 1, curr, res);
    }
};