/***                                                *
 * 1. Binary Search or Traversing the Array         *                                  
 * Time complexity : for worst case O(n)            *
 * for average: O(log n)<= O(n) <= O(n)             *
 * Space complexity :                             ***/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[end] < nums[mid]) {
                start = mid + 1;
            }
            else {
                if(nums[end] > nums[mid]) {
                    end = mid;
                }
                else {
                    if(nums[mid] == nums[start]) {
                        end--;
                        start++;
                    } 
                    else {
                        end = mid;
                    }
                }
            }
        }
        return nums[start];
    }
};