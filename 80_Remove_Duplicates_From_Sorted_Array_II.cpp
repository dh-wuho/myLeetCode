/***                                                *
 * 1. Two Pointers                                  *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i < 2 || nums[i] > nums[index - 2]) {
                nums[index++] = nums[i];
            }
        }
        
        return index;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() <= 2) {
            return nums.size();
        }
        
        int index = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[index - 1]) {
                cnt = 1;
                nums[index++] = nums[i];
            }
            else {
                if(cnt < 2) {
                    cnt++;
                    nums[index++] = nums[i];
                }
            }
        }
        
        return index;
    }
};



// when duplicates are allowed at most K times
class Solution {
public:
    int removeDuplicates(vector<int>& nums, int k) {
        
        if(nums.size() <= k) {
            return nums.size();
        }
        
        int index = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[index - 1]) {
                cnt = 1;
                nums[index++] = nums[i];
            }
            else {
                if(cnt < k) {
                    cnt++;
                    nums[index++] = nums[i];
                }
            }
        }
        
        return index;
    }
};