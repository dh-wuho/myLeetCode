class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if(sLen != tLen) {
            return false;
        }
        
        vector<int> sMap(256, 0);
        vector<int> tMap(256, 0);
        
        for(int i = 0; i < sLen; i++) {
            if(sMap[s[i]] != tMap[t[i]]) {
                return false;
            }
            sMap[s[i]] = i + 1;
            tMap[t[i]] = i + 1;
        }
        
        return true;
    }
};