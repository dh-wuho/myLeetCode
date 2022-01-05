class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, "", res);
        return res;
    }
    
    void dfs(string s, int depth, string currRes, vector<string>& res) {
        if(depth == 4) {
            if(s.empty()) {
                res.push_back(currRes);
            }
            return;
        }
        
        for(int i = 0; i < 3; i++) {
            if(s.size() < i + 1) {
                break;
            }
            string tmp = s.substr(0, i + 1);
            int val = stoi(tmp);
            if(val > 255 || i + 1 != to_string(val).size()) {
                break;
            }
            // this part, currRes doesn't change. Usually we change currRes before
            // recursion and retore it after call itself.
            dfs(s.substr(i + 1), depth + 1, currRes + tmp + (depth == 3 ? "" : "."), res);
        }
    }
};