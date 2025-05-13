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


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # let's code it out in a more succint way
        # Input: nums = [1,12,-5,-6,50,3], k = 4
        #                 0  1  2  3  4  5

        curr = 0
        for i in range(k):  # 0, 1, 2, 3
            curr += nums[i]  # 1 +12 -5 -6 = 2

        ans = curr  # 48
        for i in range(k, len(nums)):  # i = 5
            curr += nums[i] - nums[i - k]  # curr = 48 + 3 -12 = 39
            ans = max(ans, curr)  # ans = 48

        return ans / k
