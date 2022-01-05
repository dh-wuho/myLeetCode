class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>> trees;
        for(int i = 0; i < forest.size(); i++) {
            for(int j = 0; j < forest[0].size(); j++) {
                if(forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }
        
        // according to the first element in the vector.
        sort(trees.begin(), trees.end());
        
        int sr = 0;
        int sc = 0;
        int res = 0;
        
        for(int i = 0; i < trees.size(); i++) {
            int tr = trees[i][1];
            int tc = trees[i][2];
            int tmp = bfs(forest, sr, sc, tr, tc);
            if(tmp == -1) {
                return -1;
            }
            res += tmp;
            sr = tr;
            sc = tc;
        }
        
        return res;
    }
    
    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        
        if (sr == tr && sc == tc) return 0;
        
        
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int steps = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int currR = q.front().first;
                int currC = q.front().second;
                q.pop();
                
                if(currR == tr && currC == tc) {
                    return steps;
                }
                
                for(int j = 0; j < 4; j++) {
                    int nextR = currR + dir[j][0];
                    int nextC = currC + dir[j][1];
                    
                    if(nextR < 0 || nextR + 1 > m || nextC < 0 || nextC + 1 > n || visited[nextR][nextC] || forest[nextR][nextC] == 0) {
                        continue;
                    }
                    
                    q.push(make_pair(nextR, nextC));
                    visited[nextR][nextC] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};