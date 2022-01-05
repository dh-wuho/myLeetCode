class Solution {
public:
    int divide(int dividend, int divisor) {
        long divd = abs((long)dividend);
        long divs = abs((long)divisor);
        long res = 0;
        while(divd >= divs) {
            long currNum = 1;
            long currDivs = divs;
            while(divd >= (currDivs << 1)) {
                currDivs <<= 1;
                currNum <<= 1;
            }
            res += currNum;
            divd -= currDivs;
        }
        if((dividend < 0) ^ (divisor < 0)) {
            res = -res;
        }
        return res > INT_MAX ? INT_MAX : res;
    }
};