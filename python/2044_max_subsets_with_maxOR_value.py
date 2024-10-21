from typing import List

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or_value = 0
        n = len(nums)

        # Calculate the maximum OR value
        for num in nums:
            max_or_value |= num

        # index based memoization array?
        memo = [[-1] * (max_or_value + 1) for _ in range(n)]

        return self._count_subsets_recursive(nums, 0, 0, max_or_value, memo)

    def _count_subsets_recursive(
        self,
        nums: List[int],
        index: int,
        current_or: int,
        target_or: int,
        memo: List[List[int]],
    ) -> int:
        if index == len(nums):
            return 1 if current_or == target_or else 0
        if memo[index][current_or] != -1:
            return memo[index][current_or]
        count_without = self._count_subsets_recursive(
            nums, index + 1, current_or, target_or, memo
        )
        count_with = self._count_subsets_recursive(
            nums, index + 1, current_or | nums[index], target_or, memo
        )
        memo[index][current_or] = count_with + count_without
        return count_with + count_without