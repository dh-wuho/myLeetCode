/***                                                *
 * 1. Two Pointers                                  *                              
 * Time complexity: O(n)                            *
 * Space complexity:                              ***/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        while(start < end) {
            int minHeight = min(height[start], height[end]);
            maxArea = max(maxArea, (end - start) * minHeight);
            if(height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }
        return maxArea;
    }
};