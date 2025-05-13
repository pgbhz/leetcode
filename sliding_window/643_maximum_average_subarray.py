"""
Maximum Average Subarray

    GOAL
        - we want to maximize the value of a property
        - that property is the average
        - and we want that property to hold within a contiguous subarray of length k

    REQ
        - return the value of the maximum average
        - accepted error within a 10^-5 margin (does this tells us something?)

    PLAN
        - consider a subarray starting from 0 to k
            - move it until it reaches the end
            - for each move, delete its first element and add the last
            - no need to do a divison each time, just find a max sum and then divide
"""

from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        if not nums or k > len(nums):
            return None

        # calculate the first array sum
        summation = 0.0
        for idx in range(k):
            summation += nums[idx]

        # start sliding the array
        max_summation = summation
        left, right = 0, k - 1
        while right < len(nums) - 1:
            summation -= nums[left]
            left += 1  # 2
            right += 1  # 5
            summation += nums[right]
            max_summation = max(max_summation, summation)
        return max_summation / k
