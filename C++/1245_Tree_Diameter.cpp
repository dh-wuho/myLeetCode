class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        for(vector<int> edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        int res = 0;
        dfs(0, -1, g, res);
            
        return res;
    }
    
    int dfs(int curr, int parent, unordered_map<int, vector<int>>& g, int& res) {
        if(g[curr].size() == 1 && g[curr][0] == parent) {
            return 1;
        }
        
        
        int firstMax = 0;
        int secondMax = 0;
        for(int next : g[curr]) {
            if(next == parent) {
                continue;
            }
            int tmp = dfs(next, curr, g, res);
            if(tmp > firstMax) {
                secondMax = firstMax;
                firstMax = tmp;
            }
            else if(tmp > secondMax) {
                secondMax = tmp;
            }
            res = max(res, firstMax + secondMax);
        }
        
        return firstMax + 1;
    }
    
};