class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res += (n & 1);
            n = n >> 1;
        }
        return res;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};