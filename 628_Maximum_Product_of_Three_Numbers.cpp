class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        return max(nums[0] * nums[1] * nums[size - 1], nums[size - 1] * nums[size - 2] * nums[size - 3]);
    }
};



class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for(int num : nums) {
            if(num > max3) {
                max1 = max2;
                max2 = max3;
                max3 = num;
            }
            else if(num > max2) {
                max1 = max2;
                max2 = num;
            }
            else if(num > max1) {
                max1 = num;
            }       
            
            if(num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if(num < min2) {
                min2 = num;
            }
        }
        
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};