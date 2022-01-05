class Solution {
public:
    bool isNumber(string s) {
        bool num = false;
        bool dot = false;
        bool sign = false;
        bool exp = false;
        bool validExp = true;
        int length = s.size();
        
        for(int i = 0; i < length; i++) {
            if(s[i] == ' ') {
                if( i < length - 1 && s[i + 1] != ' ' && (num || dot || sign || exp)) {
                    return false;
                }
            }
            else if(s[i] == '+' || s[i] == '-') {
                if(i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') {
                    return false;
                }
                sign = true;
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                num = true;
                validExp = true;
            }
            else if(s[i] == '.') {
                if(dot || exp) {
                    return false;
                }
                dot = true;
            }
            else if(s[i] == 'e') {
                if(exp || !num) {
                    return false;
                }
                exp = true;
                validExp = false;
            }
            else {
                return false;
            }    
        }
        return num && validExp;
    }
};