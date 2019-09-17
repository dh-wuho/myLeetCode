class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> m(26, 0);
        vector<int> visited(26, 0);
        
        string res = "0";
        
        for(char c : s) {
            m[c - 'a']++;
        }
        
        for(char c : s) {
            m[c - 'a']--;
            if(visited[c - 'a']) {
                continue;
            }
            while(res.back() != '0' && c < res.back() && m[res.back() - 'a']) {
                visited[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res += c;
            visited[c - 'a'] = 1;
        }
        
        return res.substr(1);
    }
};