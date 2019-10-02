class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;

        for(int i = 0; i < n * 2; i++) {
            int num = nums[i % n];
            while(!stk.empty() && nums[stk.top()] < num) {
                res[stk.top()] = num;
                stk.pop();
            }
            if(i < n) {
                stk.push(i);   
            }
        }
        
        return res;
    }
};