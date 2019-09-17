/***                                                *
 * 1. Greedy                                        *                              
 * Time complexity: O(n)                            *
 * Space complexity: O(1)                         ***/

class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd = 0;
        int furthest = 0;
        int jumps = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            furthest = max(furthest, i + nums[i]);
            if(i == currEnd) {
                jumps++;
                currEnd = furthest;
            }
        }
        
        return jumps;
    }
};