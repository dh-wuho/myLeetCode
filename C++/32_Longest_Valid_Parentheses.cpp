class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.emplace(-1);
        
        int maxLength = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.emplace(i);
            }
            else {
                stk.pop();
                if(stk.empty()) {
                    stk.emplace(i);
                }
                else {
                    maxLength = max(maxLength, i - stk.top());
                }
            }
        }
        
        return maxLength;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int sL = s.size();
        for(int i = 0; i < sL; i++) {
            if(s[i] == '(') {
                left++;
            }
            else {
                right++;
            }
            if(left == right) {
                maxLength = max(maxLength, left * 2);
            }
            else {
                if(right > left) {
                    left = 0;
                    right = 0;
                }
            }
        }
        
        left = 0;
        right = 0;
        
        for(int i = sL - 1; i > -1; i--) {
            if(s[i] == ')') {
                right++;
            }
            else {
                left++;
            }
            if(left == right) {
                maxLength = max(maxLength, left * 2);
            }
            else {
                if(left > right) {
                    left = 0;
                    right = 0;
                }
            }
        }
        
        return maxLength;
    }
    
};