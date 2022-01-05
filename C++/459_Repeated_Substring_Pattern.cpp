class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        
        for(int i = 1; i <= len / 2; i++) {
            if(len % i == 0) {
                string curr = s.substr(0, i);
                string tmp = "";
                for(int j = 0; j < len / i; j++) {
                    tmp += curr;
                }
                if(tmp == s) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return (str + str).substr(1, str.size() * 2 - 2).find(str) != -1;
    }
};