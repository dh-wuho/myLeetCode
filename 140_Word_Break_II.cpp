class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if(s == "") {
            // here must return a vector with empty string.
            return {""};
        }
        if(m.count(s)) {
            return m[s];
        }
        
        for(string word:wordDict) {
            if(s.substr(0, word.size()) != word) {
                continue;
            }

            vector<string> remaining = wordBreak(s.substr(word.size()), wordDict);
            for(string str:remaining) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        
        m[s] = res;
        return res;
    }
};