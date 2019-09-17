class Solution {
public:
    string intToRoman(int num) {
        const string THOUS[] = {"", "M", "MM", "MMM"};
        const string HUNDS[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const string TENS[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const string ONES[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        string res = "";
        res = THOUS[num / 1000] + HUNDS[num % 1000 / 100] + TENS[num % 100 / 10] + ONES[num%10];

        return res;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        const string metaStr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        const int metaInt[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string res = "";
        
        for(int i = 0; num != 0; i++) {
            while(num >= metaInt[i]) {
                num -= metaInt[i];
                res += metaStr[i];
            }
        }
        
        return res;
    }
};