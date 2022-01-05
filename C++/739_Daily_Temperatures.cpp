class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> res(T.size());
        
        for(int i = 0; i < T.size(); i++) {
            while(!stk.empty() && T[i] > T[stk.top()]) {
                int tmp = stk.top();
                stk.pop();
                res[tmp] = i - tmp;
            }
            stk.push(i);
        }
        
        return res;
    }
};