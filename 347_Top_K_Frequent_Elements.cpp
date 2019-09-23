class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) {
            m[num]++;
        }
        
        priority_queue<pair<int, int>> mxHeap;
        for(auto it : m) {
            mxHeap.push({it.second, it.first});
        }
        
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(mxHeap.top().second);
            mxHeap.pop();
        }
        
        return res;
    }
};