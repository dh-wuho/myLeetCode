class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {      
        
        return dfs(maze, start[0], start[1], destination);
    }
    
    bool dfs(vector<vector<int>>& maze, int r, int c, vector<int>& destination) {
        if(r == destination[0] && c == destination[1]) {
            return true;
        }
        
        if(maze[r][c] == 2) {
            return false;
        }
        
        maze[r][c] = 2;
        
        for(vector<int> dir : dirs) {
            int nextR = r;
            int nextC = c;
            while(nextR > -1 && nextR < maze.size() && nextC > -1 && nextC < maze[0].size() && maze[nextR][nextC] != 1) {
                nextR += dir[0];
                nextC += dir[1];
            }   
            nextR -= dir[0];
            nextC -= dir[1];
            
            if(dfs(maze, nextR, nextC, destination)) {
                return true;
            }
        }

        return false;
    }
};


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<int> q;
        q.push(start[0]);
        q.push(start[1]);
        
        while(!q.empty()) {
            int currR = q.front();
            q.pop();
            int currC = q.front();
            q.pop();
            
            if(maze[currR][currC] == 2) {
                continue;
            }
            maze[currR][currC] = 2;
            
            if(currR == destination[0] && currC == destination[1]) {
                return true;
            }
            
            for(auto dir : dirs) {
                int nextR = currR;
                int nextC = currC;
                while(nextR > -1 && nextR < maze.size() && nextC > -1 && nextC < maze[0].size() && maze[nextR][nextC] != 1) {
                    nextR += dir[0];
                    nextC += dir[1];
                }
                nextR -= dir[0];
                nextC -= dir[1];
                
                if(maze[nextR][nextC] != 2) {
                    q.push(nextR);
                    q.push(nextC);
                }
            }
        }
        
        return false;
    }
};