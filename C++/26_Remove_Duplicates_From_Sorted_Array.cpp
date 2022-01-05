/***                                                *
 * 1. Two Pointers                                  *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(index < 1 || nums[i] > nums[index - 1]) {
                nums[index++] = nums[i];
            }
        }
        
        return index;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 0;
        }
        
        int index = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[index]) {
                nums[++index] = nums[i];
            }
        }
        
        return index + 1;
    }
};