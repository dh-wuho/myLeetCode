class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            int tmp = res;
            res = res * 10 + x % 10;
            // check overflow
            if(res / 10 != tmp) {
                return 0;
            }
            x /= 10;
        }
        return res; 
    }
};