class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {    
        int h = maze.size();
        int w = maze[0].size();
        
        vector<vector<int>> distances(h, vector<int>(w, -1));
        distances[start[0]][start[1]] = 0;
        
        queue<int> q;
        q.push(start[0]);
        q.push(start[1]);
        while(!q.empty()) {
            int r = q.front();
            q.pop();
            int c = q.front();
            q.pop();
            
            for(auto dir : dirs) {
                int nextR = r;
                int nextC = c;
                int dist = distances[r][c];
                
                while(nextR > -1 && nextR < maze.size() && nextC > -1 && nextC < maze[0].size() && maze[nextR][nextC] == 0) {
                    nextR += dir[0];
                    nextC += dir[1];
                    dist++;
                }
                
                nextR -= dir[0];
                nextC -= dir[1];
                dist--;
                
                if(distances[nextR][nextC] == -1 || dist < distances[nextR][nextC]) {
                    distances[nextR][nextC] = dist;
                    q.push(nextR);
                    q.push(nextC);
                }
            }
        }
        
        return distances[destination[0]][destination[1]];
    }

};



// DFS TLE
class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {    
        int h = maze.size();
        int w = maze[0].size();
        
        vector<vector<int>> distances(h, vector<int>(w, h * w + 1));
        distances[start[0]][start[1]] = 0;
        dfs(maze, start[0], start[1], destination, distances);
        
        int res = distances[destination[0]][destination[1]];
        return res == (h * w + 1) ? -1 : res;
    }
    
    void dfs(vector<vector<int>>& maze, int r, int c, vector<int>&destination, vector<vector<int>>& dis) {
        if(r == destination[0] && c == destination[1]) {
            return;
        }
        
        for(vector<int> dir : dirs) {
            int cnt = 0;
            int nextR = r;
            int nextC = c;
            while(nextR > -1 && nextR < maze.size() && nextC > -1 && nextC < maze[0].size() && maze[nextR][nextC] != 1) {
                nextR += dir[0];
                nextC += dir[1];
                cnt++;
            }
            nextR -= dir[0];
            nextC -= dir[1];
            cnt--;
            
            if(dis[r][c] + cnt < dis[nextR][nextC]) {
                dis[nextR][nextC] = dis[r][c] + cnt;
                dfs(maze, nextR, nextC, destination, dis);
            }
        }
    }
};