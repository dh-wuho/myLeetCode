class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26, false));
        vector<bool> visited(26, false);
        string res = "";
        
        for(string word : words) {
            for(char c : word) {
                g[c - 'a'][c - 'a'] = true;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            int shorter = min(words[i].size(), words[i + 1].size());
            int j = 0;
            for(; j < shorter; j++) {
                if(words[i][j] != words[i + 1][j]) {
                    g[words[i][j] - 'a'][words[i + 1][j] - 'a'] = true;
                    break;
                }
            }
            if(j == shorter && words[i].size() > words[i + 1].size()) {
                return "";
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(!dfs(g, i, visited, res)) {
                return "";
            }
        }
        
        return res;
    }
    
    
    bool dfs(vector<vector<bool>>& g, int curr, vector<bool>& visited, string& res) {
        
        // 出度为0
        if(!g[curr][curr]) {
            return true;
        }
        
        visited[curr] = true;
        for(int i = 0; i < 26; i++) {
            if(i == curr || !g[i][curr]) {
                continue;
            }
            if(visited[i]) {
                return false;
            }
            if(!dfs(g, i, visited, res)) {
                return false;
            }
        }
        
        visited[curr] = false;
        g[curr][curr] = false;
        res += 'a' + curr;
        return true;
    }
};