/***                                                *
 * 1. Count number of letters                       *                                  
 * Time complexity : O(n)                           *
 * Space complexity :                             ***/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> aUmap;
        unordered_map<char, int>::iterator iter;
        
        for(int i = 0; i < s.length(); i++) {
            aUmap[s[i]]++;
            aUmap[t[i]]--;
        }
        
        for(iter = aUmap.begin(); iter != aUmap.end(); iter++) {
            if(iter->second != 0) {
                return false;
            }
        }
        return true;
    }
};