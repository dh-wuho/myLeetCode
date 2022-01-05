#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
# 
# Time: O(n)
# Space: O(n)

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numToIndex = {}
        for i, num in enumerate(nums):
            diff = target - num
            if target - num in numToIndex:
                return i, numToIndex[diff]
            else:
                numToIndex[num] = i
        return []

# @lc code=end

