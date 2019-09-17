/***                                                *
 * 1. Binary Search or Traversing the Array         *                                  
 * Time complexity : for worst case O(n)            *
 * for average: O(log n)<= O(n) <= O(n)             *
 * Space complexity :                             ***/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) {
            return false;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                return true;
            }
            
            if(nums[mid] == nums[start] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;
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
        return nums[start] == target ? true : false;
    }
};