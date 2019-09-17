class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0) {
            return res;
        }
        res.resize(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int x = 0;
        int y = 0;
        int di = 0;
        for(int i = 0; i < n * n; i++) {
            res[x][y] = i + 1;
            visited[x][y] = true;
            int nx = x + dx[di];
            int ny = y + dy[di];
            if(nx > -1 && nx < n && ny > -1 && ny < n && !visited[nx][ny]) {
                x = nx;
                y = ny;
            }
            else {
                di = (di + 1) % 4;
                x += dx[di];
                y += dy[di];
            }
        }
        
        return res;
    }
};