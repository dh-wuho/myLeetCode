class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        // 0 = unvisited; 1 = visiting; 2 = visited;
        vector<int> visited(numCourses, 0);
        vector<int> res;
        
        for(auto pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(dfs(adjList, i, res, visited)) {
                    return {};
                }
            }
        }
        
        reverse(res.begin(), res.end());       
        return res;
    }
    
    // ret means if cycle exists
    bool dfs(vector<vector<int>>& adjList, int curr, vector<int>& res, vector<int>& visited) {
        if(visited[curr] == 2) {
            return false;
        }
        
        if(visited[curr] == 1) {
            return true;
        }
        
        visited[curr] = 1;
        for(int next : adjList[curr]) {
            if(dfs(adjList, next, res, visited)) {
                return true;
            }
        }
        
        visited[curr] = 2;
        res.push_back(curr);
        return false;
    }
};