class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() == 0) {
            return image;
        }
        
        if(image[sr][sc] != newColor) {
            dfs(image, sr, sc, image[sr][sc], newColor);
        }
        
        return image;
    }
    
    void dfs(vector<vector<int>>& img, int r, int c, int startColor, int newColor) {
        if(r < 0 || r + 1 > img.size() || c < 0 || c + 1 > img[0].size() || img[r][c] != startColor) {
            return;
        }
        
        img[r][c] = newColor;
        dfs(img, r - 1, c, startColor, newColor);
        dfs(img, r, c + 1, startColor, newColor);
        dfs(img, r + 1, c, startColor, newColor);
        dfs(img, r, c - 1, startColor, newColor);
    }
};