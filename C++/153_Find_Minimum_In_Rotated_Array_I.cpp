/***                                                *
 * 1. Binary Search                                 *                                  
 * Time complexity : O(logN)                        *
 * Space complexity :                             ***/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums[end] > nums[mid]) {
                end = mid;
            }
            else {
                start = mid;
            }
        }
        
        if(nums[start] > nums[end]) {
            return nums[end];
        }
        
        return nums[start];
    }
};