class Solution {
public:
    string addBinary(string a, string b) {
        int aL = a.size();
        int bL = b.size();
        int carry = 0;
        string res = "";
        for(int i = aL - 1, j = bL - 1; i > -1 || j > -1; i--, j--) {
            int num1 = (i > -1) ? (a[i] - '0') : 0;
            int num2 = (j > -1) ? (b[j] - '0') : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 2;
            res = to_string(sum % 2) + res;
        }
        if(carry) {
            res = '1' + res;
        }
        
        return res;
    }
};