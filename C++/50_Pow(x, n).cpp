/***                                                *
 * 1. Binary                                        *                                  
 * Time complexity : O(log n)                       *
 * Space complexity :                             ***/

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0) {
            return 1;
        }
        
        double res = 1.0;
        
        for(int i = n; i != 0; i /= 2) {
            if(i % 2 != 0) {
                res *= x;
            }
            x *= x;
        }
        
        return n < 0 ? 1 / res : res;
    }
};

/***                                                *
 * 2. Recursion                                     *                                  
 * Time complexity : O(log n)                       *
 * Space complexity :                             ***/

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0) {
            return 1.0;
        }
        
        double half = myPow(x, n / 2);
        if(n % 2 != 0) {
            return n > 0 ? half * half * x : 1 / x * half * half;
        }
        return half * half;
        
    }
};