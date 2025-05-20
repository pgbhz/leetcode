# sliding window with auto discard
# apparently some dude named Kadane got the credit for it
# wish it was that easy nowadays

"""
Why did I skip all my procedures?

- return the sum of the max subarray
"""

from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_so_far = curr_max = nums[0]
        start_idx = end_idx = j = 0

        for i in range(1, len(nums)):
            if nums[i] > curr_max + nums[i]:
                curr_max = nums[i]
                j = i
            else:
                curr_max += nums[i]

            if curr_max > max_so_far:
                max_so_far = curr_max
                start_idx = j
                end_idx = i

        print(start_idx, end_idx)
        return max_so_far
