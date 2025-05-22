"""
My intuition is god like, this is dynamic programming.
Why? Because we want to make intermediate decisions which minimize a final outcome.
Is there a greedy approach? No, if we jump max or min, it doesn't guarantee that this will solve the problem.

For each position, we jump to all allowed positions.
We cache each position, but how? What exactly do we cache?
What's our base case? We return the number of jumps when we get to the final position.

0 <= j <= nums[i] and
i + j < n

Those two equations tell me that it's impossible to jump beyond the array.
"""

# This looks solid.


class Solution:
    def min_jumps_from_to_end(self, i: int, nums: List[int], cache: List[int]):
        if i >= len(nums) - 1:
            return 0
        if cache[i] is not None:
            return cache[i]
        cache[i] = float("inf")
        for jump_size in range(nums[i] + 1):
            if i + jump_size >= len(nums):
                continue
            if not cache[i + jump_size]:
                cache[i] = min(
                    cache[i], 1 + self.min_jumps_from_to_end(i + jump_size, nums, cache)
                )
            else:
                cache[i] = min(cache[i], 1 + cache[i + jump_size])
        return cache[i]

    def jump(self, nums: List[int]) -> int:
        cache = [None for _ in range(len(nums))]
        return self.min_jumps_from_to_end(0, nums, cache)
