class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int> > graph(N);
        vector<int> res(N, 0);
        
        // build the graph
        for(int i = 0; i < paths.size(); i++) {
            graph[paths[i][0] - 1].push_back(paths[i][1] - 1);
            graph[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }
        
        for(int i = 0; i < N; i++) {
            vector<bool> used(5, false);
            for(int j = 0; j < graph[i].size(); j++) {
                used[res[graph[i][j]]] = true;
            }
            
            for(int color = 1; color <= 4; color++) {
                if(!used[color]) {
                    res[i] = color;
                    break;
                }
            }
        }
        
        return res;
    }
};