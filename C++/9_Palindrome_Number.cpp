/***                                                *
 * 1. Divide the number into 2 parts then Compare   *                                  
 * Time complexity : O(n)                           *
 * Space complexity :                             ***/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) {
            return true;
        }
        
        if(x < 0 || x % 10 == 0) {
            return false;
        }
        
        int y = 0;
        while(y < x) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return (x == y) || (x == y / 10);
    }
};

/***                                                *
 * 2. Converse to String and to check Palindrome    *                                       *                                  
 * Time complexity : O(n)                           *
 * Space complexity :                             ***/
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) {
            return false;
        }
        
        string s = to_string(x);
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};