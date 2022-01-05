/***                                                *
 * 1. Greedy                                        *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = nums.size() - 1;
        for(int i = nums.size() - 1; i > -1; i--) {
            if(i + nums[i] >= furthest) {
                furthest = i;
            }
        }
        return furthest == 0;
    }
};

/***                                                *
 * 2. DP                                            *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            step--;
            if(step < 0) {
                return false;
            }
            if(nums[i] > step) {
                step = nums[i];
            }
        }
        return true;
    }
};