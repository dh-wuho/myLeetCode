class Solution {
public:
    int brokenCalc(int X, int Y) {        
        int res = 0;
        while(X < Y) {
            if(Y % 2 == 1) {
                Y++;
            }
            else {
                Y = Y >> 1;
            }
            res++;
        }
        
        return res + X - Y;
    }
};