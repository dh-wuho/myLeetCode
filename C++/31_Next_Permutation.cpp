class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        int first = length - 2;
        
        while(first >= 0 && nums[first] >= nums[first + 1]) {
            first--;
        }
        if(first >= 0) {
            int second = length - 1;
            while(nums[first] >= nums[second]) {
                second--;
            }
            swap(nums[first], nums[second]);
        }

        reverse(nums.begin() + first + 1, nums.end());
    }
};