class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int currLen = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                if(nums[i] - nums[i - 1] == 1) {
                    currLen++;
                }
                else {
                    longest = max(longest, currLen);
                    currLen = 1;
                }
            }
        }
        return max(longest, currLen);
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> table(nums.begin(), nums.end());
        int longest = 0;
        for(int val : nums) {
            if(!table.count(val)) {
                continue;
            }
            table.erase(val);
            int currLen = 1;
            int prev = val - 1;
            int next = val + 1;
            while(table.count(prev)) {
                table.erase(prev);
                prev--;
            }
            while(table.count(next)) {
                table.erase(next);
                next++;
            }
            longest = max(longest, next - prev - 1);
        }
        
        return longest;
    }
};