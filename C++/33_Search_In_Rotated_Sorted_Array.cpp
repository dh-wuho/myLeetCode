/***                                                *
 * 1. Binary Search                                 *                                  
 * Time complexity : O(log N)                       *
 * Space complexity :                             ***/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) {
            return -1;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                return mid;
            }
            
            if(nums[mid] < nums[start]) {
                if(nums[mid] < target && target < nums[start]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            else {
                if(nums[mid] > target && target >= nums[start]) {
                    end = mid;
                }        
                else {
                    start = mid + 1;
                }
            }        
        }
        
        return nums[start] == target ? start : -1;
    }
};