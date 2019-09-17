class Solution {
public:
    string frequencySort(string s) {
        string res;
        if(s.empty()) {
            return s;
        }
        
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        
        for(char c : s) {
            m[c]++;
        }
        for(auto it : m) {
            q.push(make_pair(it.second, it.first));
        }
        
        while(!q.empty()) {
            pair<int, char> tmp = q.top();
            q.pop();
            for(int i = 0; i < tmp.first; i++) {
                res += tmp.second;
            }
        }
        
        return res;
    }
};



class Solution {
public:
    string frequencySort(string s) {
        if(s.empty()) {
            return s;
        }
        
        int len = s.size(); 
        string res;
        vector<string> bucket(len, "");
        unordered_map<char, int> m;
        
        for(char c : s) {
            m[c]++;
        }
        
        for(auto it : m) {
            bucket[it.second - 1].append(it.second, it.first);
        }
        
        for(int i = len - 1; i > -1; i--) {
            if(!bucket[i].empty()) {
                res.append(bucket[i]);
            }
        }
        
        return res;
    }
};