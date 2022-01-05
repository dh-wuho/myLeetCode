#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
from typing import List

# @lc code=start
# Sort the list first. Then fix one number 
# and use 2 pointers to check the rest numbers.
# Need to skip repeated numbers for both fixed number and in 2 pointers
# Space: O(1)
# Time: O(n^2)

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        if n < 3:
            return res
        nums.sort()

        for i in range(n - 2):
            if nums[i] > 0:
                return res
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = n - 1
            
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]: 
                        left += 1
                    while left < right and nums[right] == nums[right - 1]: 
                        right -= 1
                    left += 1
                    right -= 1
                elif sum < 0:
                    left += 1
                else:
                    right -= 1

        return res

# @lc code=end