   static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    int romanToInt(string s) {
        if(s.empty()) {
            return 0;
        }
        
        unordered_map<char, int> table = { {'I', 1},
                                           {'V', 5},
                                           {'X', 10},
                                           {'L', 50},
                                           {'C', 100},
                                           {'D', 500},
                                           {'M', 1000} };
        int rtn = table[s.back()];
        for(int i = 0; i < s.size()-1; i++) {
            if(table[s[i]] < table[s[i+1]]) {
                rtn -= table[s[i]];
            }
            else {
                rtn += table[s[i]];
            }
        }
        
        return rtn;
    }
};

