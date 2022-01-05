#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#
# Time: O(n)
# Space: O(1)

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        uniq = 0
        for currNum in nums:
            if nums[uniq] != currNum:
                uniq += 1
                nums[uniq] = currNum
        return uniq + 1
# @lc code=end

