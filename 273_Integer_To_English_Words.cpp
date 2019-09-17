class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }
        string res = toHundred(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for(int i = 0; i < 3; i++) {
            num /= 1000;
            res = num % 1000 ? toHundred(num % 1000) + " " + v[i] + " " + res : res;

        }
        if(res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
    
    string toHundred(int num) {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int hnd = num / 100;
        int ten = num % 100;
        int digit = num % 10;
        
        if(ten < 20) {
            res = v1[ten];
        }
        else {
            res = v2[ten / 10] + (digit ? " " + v1[digit] : "");
        }
        
        if(hnd > 0) {
            res = v1[hnd] + " Hundred" + (ten ? " " + res : "");
        }
        
        return res;
    }
};