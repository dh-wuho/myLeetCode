/***                                                *
 * 1. Math                                          *                              
 * Time complexity: O(sqrt(n))                      *
 * Space complexity: O(1)                         ***/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int base = 1;
        while(num > 0) {
            num -= base;
            base += 2;
        }
        
        return num == 0;
    }
};


/***                                                *
 * 2. Binary Search                                 *                              
 * Time complexity: O(lg(n))                        *
 * Space complexity: O(1)                         ***/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while(left <= right) {
            long mid = left + (right - left) / 2;  
            if(mid * mid == num) {
                return true;
            }
            else if(mid * mid < num) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};


/***                                                *
 * 3. Newton Method                                 *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long tmp = num;
        while(tmp * tmp > num) {
            tmp = (tmp + num/tmp) >> 1;
        }
        return tmp * tmp == num;
    }
};