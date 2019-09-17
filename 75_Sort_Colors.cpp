class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int curr = 0;
        int p2 = nums.size() - 1;
        
        while(curr <= p2) {
            if(nums[curr] == 0) {
                swap(nums[curr], nums[p0]);
                curr++;
                p0++;
            }
            else if(nums[curr] == 2) {
                swap(nums[curr], nums[p2]);
                p2--;
            }
            else {
                curr++;
            }
        }
    }
};