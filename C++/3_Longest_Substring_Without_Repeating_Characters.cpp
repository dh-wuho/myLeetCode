/***                                                *
 * 1. brute force                                   *
 * Time complexity: O(n^3);                         *
 * Space complexity: O(min(n, m));                  *
 * The size of the Set is upper bounded by the      *
 * size of the string nn and the size of the        *
 * charset/alphabet m.                            ***/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int length = s.size();
        int res = 0;
        
        for(int i = 0; i < length; i++) {
            for( int j = i + 1; j < length + 1; j++) {
                if(allUnique(s, i, j)) {
                    res = max(res, j - i);
                }
            }
        }
        
        return res;
    }
    
    bool allUnique(string s, int begin, int end) {
        
        set<char> aSet;
        
        for(int i = begin; i < end; i++) {
            if(aSet.count(s[i])) {
                return false;
            }
            aSet.insert(s[i]);
        }
        return true;
    }
};

/***                                                *
 * 2. Sliding Window                                *
 * Given a set(windows) to store the requested      *
 * substring, i to mark the left edge and j to mark *
 * the right edge. When a new letter comes to the   *
 * window, if it is in the window, the left edge    *
 * moves to right, if not, the right edge moves to  *
 * right.                                           *
 * Time complexity : O(2n) = O(n)O(2n)=O(n). In the *
 * worst case each character will be visited twice  *
 * by i and j.                                      *
 * Space complexity : O(min(m, n)).               ***/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> aSet;
        int res = 0;
        int i, j;
        
        for(i = 0, j = 0; j < s.size();) {
            if(aSet.count(s[j])) {
                aSet.erase(s[i++]);
            }
            else {
                aSet.insert(s[j++]);
                res = max(res, j - i);
            }
        }
        
        return res;
    }
};


/***                                                   *
 * 3. Sliding Window Optimized                         * 
 * If we know that the charset is rather small, we     *
 * can replace the Map with an integer array as        *
 * direct access table.                                *
 * Commonly used tables are:                           *
 *                                                     *
 * int[26] for Letters 'a' - 'z' or 'A' - 'Z'          *
 * int[128] for ASCII                                  *
 * int[256] for Extended ASCII                       ***/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> charTab(128);
        int i, j;
        
        for(i = 0, j = 0; j < s.size(); j++) {
            i = max(charTab[s.at(j)], i);
            res = max(res, j - i + 1);
            charTab[s.at(j)] = j + 1;
        }
        
        return res;
    }
};