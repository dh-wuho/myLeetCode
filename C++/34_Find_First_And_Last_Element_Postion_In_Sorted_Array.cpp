/***                                                *
 * 1. C++ STL functions                             *                                  
 * Time complexity: O(log n)                        *
 * Space complexity:                             ***/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) {
            return {-1, -1};
        }
        
        auto lowerIt = lower_bound(nums.begin(), nums.end(), target);
        auto upperIt = upper_bound(nums.begin(), nums.end(), target) - 1;
        int lower;
        int upper;
        
        if(*lowerIt != target) {
            lower = -1;
        } 
        else {
            lower = lowerIt - nums.begin(); 
        }
            
        if(*upperIt != target) {
            upper = -1;
        }
        else {
            upper = upperIt - nums.begin();
        }
        if(lower == nums.size()) {
            lower = -1;
        }
        return {lower, upper};
    }
};


/***                                                *
 * 2. Binary Search                                 *                                  
 * Time complexity: O(log n)                        *
 * Space complexity:                             ***/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) {
            return {-1, -1};
        }
        
        int start = 0;
        int end = nums.size();
        vector<int> res;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        if(nums[start] == target && start < nums.size()) {
            res.push_back(start);
        }
        else {
            return {-1, -1};
        }
        
        start = 0;
        end = nums.size();
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] <= target) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        res.push_back(start - 1);
        
        return res;
    }
};