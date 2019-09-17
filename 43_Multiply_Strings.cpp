/***
        index    012
        num1     123
        num2     456
        -----------------
        index 012345        // because 999 * 999 < 1000000, max length of res is 6
                  18        // which equals num1.size() + num2.size()
                 12
                 6
                 15
                10
                5
                12
                8
               4
        -----------------
        res    56088                 
        ***/

class Solution {
public:
    string multiply(string num1, string num2) {        
        int l1 = num1.size();
        int l2 = num2.size(); 
        string res(l1 + l2, '0');      
        
        for(int i = l1 - 1; i > -1; i--) {
            for(int j = l2 - 1; j > -1; j--) {
                int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = tmp % 10 + '0';
                // here res[i + j] may be greater than 9, but it doesn't affect result
                // because next time when handle this digit, line 29 and 30 will make it right
                res[i + j] += tmp / 10;
            }
        }
        
        size_t startpos = res.find_first_not_of("0");
        if (startpos != string::npos) {
            return res.substr(startpos);
        }
        return "0";
    }
};