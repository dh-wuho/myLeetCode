class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> digits;
        while(N) {
            digits.push_back(N % 10);
            N /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        int start = digits.size();
        for(int i = digits.size() - 1; i > 0; i--) {
            if(digits[i - 1] > digits[i]) {
                digits[i - 1]--;
                start = i;
            }
        }
        
        int res = 0;
        for(int i = 0; i < digits.size(); i++) {
            if(i == start) {
                digits[i] = 9;
                start++;
            }
            res = res * 10 + digits[i];
        }
        
        return res;
    }
};