/***                                                *
 * 1. Consider four cases:                          *    
 *  1)discards all leading whitespaces;             *
 *  2)sign of the number;                           *
 *  3)overflow;                                     *
 *  4)invalid input;                                *                                  
 * Time complexity :                                *
 * Space complexity :                             ***/


class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int ptr = 0;
        int res = 0;
        
        while(str[ptr] == ' ') {
            ptr++;
        }
        
        if(str[ptr] == '+' || str[ptr] == '-') {
            if(str[ptr] == '-') {
                sign = -1;
            }
            ptr++;
        }
        
        while(str[ptr] >= '0' && str[ptr] <= '9') {
            int tmp = res;
            res = res * 10 + str[ptr] - '0';
            if(tmp != res / 10) {
                return sign ? INT_MAX : INT_MIN;
            }
            ptr++;
        }
        
        
        return sign * res;
    }
};


class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int ptr = 0;
        long res = 0;
        
        while(str[ptr] == ' ') {
            ptr++;
        }
        
        if(str[ptr] == '+' || str[ptr] == '-') {
            if(str[ptr] == '-') {
                sign = -1;
            }
            ptr++;
        }
        
        cout << sign << endl;
        
        while(str[ptr] >= '0' && str[ptr] <= '9') {
            res = res * 10 + str[ptr] - '0';
            if(res*sign >= INT_MAX) return INT_MAX;
            if(res*sign <= INT_MIN) return INT_MIN; 
            ptr++;
        }
        
        
        return sign * res;
    }
};