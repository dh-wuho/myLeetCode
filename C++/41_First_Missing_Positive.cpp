class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // swap nums[i] to its right place, so we need to detect the current nums[i] again
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0 && nums[i] < n + 1 && 
               nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
                i--;
            }
        }   
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1; 
    }
};