class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        if(strs.size() == 0) {
            return res;
        }
        
        unordered_map<string, vector<string> > table;
        
        for(int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            table[tmp].push_back(strs[i]);
        }
        
        for(auto a:table) {
            res.push_back(a.second);
        }
        
        return res;
    }
};