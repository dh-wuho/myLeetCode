class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0) {
            return res;
        }
        res.resize(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};
        int i = 0;
        int j = 0;
        int dir = 0;
        for(int k = 0; k < n * n; k++) {
            res[i][j] = k + 1;
            visited[i][j] = true;
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if(ni > -1 && ni < n && nj > -1 && nj < n && !visited[ni][nj]) {
                i = ni;
                j = nj;
            }
            else {
                dir = (dir + 1) % 4;
                i += di[dir];
                j += dj[dir];
            }
        }
        
        return res;
    }
};