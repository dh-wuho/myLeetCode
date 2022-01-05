class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            // i - k + 1 is the leftmost index
            if(i - k + 1 > -1) {
                res.push_back(dq.front());
                if(nums[i - k + 1] == dq.front()) {
                    dq.pop_front();
                }
            }
        }
        return res;
    }
};