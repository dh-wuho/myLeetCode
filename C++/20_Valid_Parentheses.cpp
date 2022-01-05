class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(size%2 != 0) {
            return false;
        }
        unordered_map<char, char> table = { {'(', ')'},
                                            {'[', ']'},
                                            {'{', '}'} };
        stack<char> stk;
        for(int i = 0; i < size; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } 
            else {    
                if(stk.empty()) {
                    return false;
                }
                if(table[stk.top()] == s[i]) {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }
        if(!stk.empty()) {
            return false;
        }
        return true;
    }
};