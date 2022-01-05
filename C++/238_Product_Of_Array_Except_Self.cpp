class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0) {
            return res;
        }
        
        int length = nums.size();
        res = vector<int>(length, 1);
        int leftToRight = 1;
        int rightToLeft = 1;
        for(int i = 0; i < length; i++) {
            res[i] *= leftToRight;
            leftToRight *= nums[i];
            res[length - i - 1] *= rightToLeft;
            rightToLeft *= nums[length - i - 1];
        }
        
        return res;
    }
};