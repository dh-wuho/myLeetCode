class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> onePath = {0};
        
        dfs(graph, 0, onePath, res);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& graph, int index, vector<int>& path, vector<vector<int>>& res) {
        if(index + 1 == graph.size()) {
            res.push_back(path);
        }
        
        for(int i : graph[index]) {
            path.push_back(i);
            dfs(graph, i, path, res);
            path.pop_back();
        }
    }
};