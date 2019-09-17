/***                                                *
 * 1. Using BitMap                                  *                                  
 * Time complexity : O(n)                           *
 * Space complexity :                             ***/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> aBS;
        for(auto c : s) {
            aBS.flip(c);
        }
        return aBS.count() < 2;
    }
};

/***                                                *
 * 1. Using Unordered_Map                           *                                  
 * Time complexity : O(n)                           *
 * Space complexity :                             ***/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size() == 1) {
            return true;
        }
        
        unordered_map<char, int> aMap;
        unordered_map<char, int>::iterator iter;
        for(int i = 0; i < s.size(); i++) {
            aMap[s[i]]++;
        }
        int sum = 0;
        int isOdd = 0;
        for(iter = aMap.begin(); iter != aMap.end(); iter++) {
            if(iter->second % 2 == 1) {
                isOdd++;
            }
        }
        if(isOdd > 1) {
            return false;
        }
        
        return true;
    }
};