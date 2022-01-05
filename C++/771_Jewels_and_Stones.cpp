class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> table;
        for(char c:J) {
            table.insert(c);
        }
        int jewels = 0;
        for(char c:S) {
            if(table.count(c) == 1) {
                jewels++;
            }
        }
        
        return jewels;
    }
};