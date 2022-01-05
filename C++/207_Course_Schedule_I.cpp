class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegrees(numCourses, 0);
        
        for(vector<int> pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            inDegrees[pre[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegrees[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            numCourses--;
            for(int next : adjList[curr]) {
                inDegrees[next]--;
                if(inDegrees[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return numCourses == 0;
    }
};