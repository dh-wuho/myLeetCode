class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> startIndex;
        
        int n = nums.size();
        int res = INT_MAX;
        int degree = 0;
        
        for(int i = 0; i < n; i++) {
            cnt[nums[i]]++;
            if(startIndex.find(nums[i]) == startIndex.end()) {
                startIndex[nums[i]] = i;
            }
            
            if(cnt[nums[i]] == degree) {
                res = min(res, i - startIndex[nums[i]] + 1);
            }
            else if(cnt[nums[i]] > degree) {
                res = i - startIndex[nums[i]] + 1;
                degree = cnt[nums[i]];
            }
        }
        
        return res;
    }
};