class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int closest = nums[0] + nums[1] + nums[2];
        int minDistance = abs(closest - target);
        int diff;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) {
                    return sum;
                }
                diff = abs(sum - target);
                if(diff < minDistance) {
                    minDistance = diff;
                    closest = sum;
                }
                if(sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return closest;
    }
};