class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            for(int j = 0; i + j < len && i - j > -1; j++) {
                if(s[i + j] == s[i - j]) {
                    res++;
                }
                else {
                    break;
                }
            }
            
            for(int j = 0; i + j + 1 < len && i - j > -1; j++) {
                if(s[i + j + 1] == s[i - j]) {
                    res++;
                }
                else {
                    break;
                }
            }
        }
        
        return res;
    }
};