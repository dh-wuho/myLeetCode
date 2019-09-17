class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int peri = 0;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                if(i == 0 || grid[i - 1][j] == 0) {
                    peri++;
                }
                if(j == 0 || grid[i][j - 1] == 0) {
                    peri++;
                }
                if(i + 1 == height || grid[i + 1][j] == 0) {
                    peri++;
                }
                if(j + 1 == width || grid[i][j + 1] == 0) {
                    peri++;
                }
            }
        }

        return peri;
    }
};