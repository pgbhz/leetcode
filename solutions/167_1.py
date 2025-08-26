"""
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

# Notes

    - 1-index: pay attention. This can be discarded because of the "added by one" return requirement, apparently.

    - input is sorted in non-decreasing order

    - GOAL: find two numbers such that they add up to a specific target number
        - such that:    1 <= index1 < index2 <= numbers.length

    - return the indices of these numbers as [idx1+1, idx2+1]

    - there is one solution

    - EDGE CASE 1: can't use the same element twice

    - SPACE REQUIREMENT 1: we must use O(1) extra space

# Reasoning

    - numbers must add to a specific target number k (let's call it that)
    - we know that, given number x, y will be k - x.
    - i guess we only need to find y, given x.
    - so, for each number num in nums, we ask ourselves: is y also there? if it is, boom, we've got it.
    - the thing is: we cannot use extra space. If we had access to a hash map, we would kill the job.
    - but we do know: the array is sorted non-decreasingly.
        - and this smells like binary search ! O(log(n))
        - implementing binary search will be a test, I'm sort of rusty in that. let's go for it.

"""

from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1  # 0, 1
        while left < right:
            lr_sum = numbers[left] + numbers[right]  # 9
            if (
                lr_sum == target
            ):  # this should always happen. "there is exactly one solution"
                return [left + 1, right + 1]  # return [1, 2]
            elif lr_sum < target:  # 13 !< 9
                left += 1
            elif lr_sum > target:  # 13 > 9
                right -= 1  # right = 1
