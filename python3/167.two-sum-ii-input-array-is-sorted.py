#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#
# Time: O(n)
# Space: O(1)

# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        while l < r:
            sum = numbers[l] + numbers[r]
            if sum == target:
                return l + 1, r + 1
            elif sum < target:
                l += 1
            else:
                r -= 1
        return []
        
# @lc code=end

