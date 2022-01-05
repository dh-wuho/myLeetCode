class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int, vector<int>> m;
        queue<int> q;
        int len = pid.size();
        
        for(int i = 0; i < len; i++) {
            m[ppid[i]].push_back(pid[i]);
        }
        
        q.push(kill);
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            res.push_back(tmp);
            for(int a : m[tmp]) {
                q.push(a);
            }
        }
        
        return res;
    }
};