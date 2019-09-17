class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x^y;
        y = 0;
        while(x > 0) {
            y++;
            x &= (x - 1);
        }
        
        return y;
    }
};