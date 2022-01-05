class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int h = grid.size();
        if(h == 0) {
            return 0;
        }
        int w = grid[0].size();
        set<vector<pair<int, int>>> res;
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(grid[i][j]) {
                    vector<pair<int, int>> island;
                    dfs(grid, i, j, island);
                    res.insert(canonical(island));
                }
            }
        }
        return res.size();
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c, vector<pair<int, int>>& island) {
        if(r < 0 || r + 1 > grid.size() || c < 0 || c + 1 > grid[0].size() || grid[r][c] == 0) {
            return;
        }
        
        grid[r][c] = 0;
        island.push_back({r, c});
        dfs(grid, r - 1, c, island);
        dfs(grid, r, c + 1, island);
        dfs(grid, r + 1, c, island);
        dfs(grid, r, c - 1, island);
    }
    
    vector<pair<int, int>> canonical(vector<pair<int, int>>& island) {
        vector<vector<pair<int, int>>> shapes(8);
        
        for(pair<int, int> coor : island) {
            int x = coor.first;
            int y = coor.second;
            shapes[0].push_back({x, y});
            shapes[1].push_back({x, -y});
            shapes[2].push_back({-x, y});
            shapes[3].push_back({-x, -y});
            shapes[4].push_back({y, x});
            shapes[5].push_back({y, -x});
            shapes[6].push_back({-y, x});
            shapes[7].push_back({-y, -x});
        }
        
        // in c++, to use : to traverse vector is by value parameter
        for(vector<pair<int, int>>& shape : shapes) {
            sort(shape.begin(), shape.end());
            for(int i = shape.size() - 1; i > -1; i--) {
                shape[i].first -= shape[0].first;
                shape[i].second -= shape[0].second;
            }
        }
        
        sort(shapes.begin(), shapes.end());
        return shapes[0];
    }    
};