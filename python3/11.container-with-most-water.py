#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0
        l = 0
        r = len(height) - 1
        while l < r:
            currArea = (r - l) * min(height[l], height[r])
            maxArea = max(maxArea, currArea)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return maxArea
        
# @lc code=end

