class Solution {
public:
    bool isPowerOfTwo(int n) {
        int oneS = 0;
        while(n > 0) {
            if(n & 1) {
                oneS++;
            }
            n >>= 1;
        }
        return oneS == 1;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n - 1));
    }
};