class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0) {
            if(n % 26 == 0) {
                res += "Z";
                n -= 26;
            }
            else {
                res += 'A' + n % 26 - 1;
                n -= n % 26;
            }
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n-- > 0) {
            res = char('A' + n % 26) + res;
            n /= 26;
        }

        return res;
    }
};