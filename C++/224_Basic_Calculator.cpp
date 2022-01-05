class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int operand = 0;
        int res = 0;
        stack<int> stk;
        
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                operand = operand * 10 + (s[i] - '0');
            }
            else if(s[i] == '+') {
                res += sign * operand;
                sign = 1;
                operand = 0;
            }
            else if(s[i] == '-') {
                res += sign * operand;
                sign = -1;
                operand = 0;
            }
            else if(s[i] == '(') {
                stk.push(res);
                stk.push(sign);
                // for sub-expression, we re-initialize the flags
                sign = 1;
                res = 0;
                operand = 0;
            }
            else if(s[i] == ')') {
                res += sign * operand;
                operand = 0;
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
            }
        }
        
        res += sign * operand;
        
        return res;
    }
};