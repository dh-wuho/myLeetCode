class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> table;
        int length = s.size();
        
        for(int i = 0; i < length; i++) {
            if(table.find(s[i]) != table.end()) {
                table[s[i]]++;
            }
            else {
                table[s[i]] = 1;
            }
        }
        
        for(int i = 0; i < length; i++) {

            if(table[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};