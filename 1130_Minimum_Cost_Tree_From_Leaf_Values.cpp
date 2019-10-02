class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int> stk;
        stk.push(INT_MAX);
        
        for(int a : arr) {
            while(stk.top() <= a) {
                int minOne = stk.top();
                stk.pop();
                res += minOne * min(stk.top(), a);
            }
            stk.push(a);
        }
        
        int first = stk.top();
        stk.pop();
        
        while(stk.size() != 1) {
            int second = stk.top();
            stk.pop();
            res += first * second;
            first = second;
        }
        
        return res;
    }
};