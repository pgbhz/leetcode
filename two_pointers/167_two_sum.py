"""
- Array is 1-indexed: first position is idx = 1, not 0.

- Array is composed of integers, both negative and positive, possibly.

- Array is sorted in non-decreasing order: [1, 2, 3, 3, 5]
    - Can the array contain duplicates?
        * Possibly...

- We want to find TWO numbers that add up to TARGET.

- What do you exactly mean by the two indexes "added by one"?
    - Let's walk through an example input.

- There is exactly one solution.

- We may not use the same element twice.

- We may use only constant extra space.
    - No new arrays, etc.

Let's *immediatly* think about the Brute-Force.
    What's it?
        Well, for each element, we check, for every other element, if they sum up to
        our target.
    What's the complexity?
        O(N^2) where N is the length of the array.

Ok, let's think about a better solution.
    - TRACK SEEN NUMBERS. For any given number X, we know that
    if we have TARGET - X in the array, we have a solution for our problem.
    But that requires extra space, namely an additional hash map to keep track
    of seen elements.

    - TWO POINTERS. As the array is sorted in non-decreasing order, we know
    that if we increase a left pointer, the increment the sum, and, if we
    decrement a right pointer, we decrement the sum. We can use these pointers
    as some sort of dial, fine tuning our sum until we reach target, or don't
    reach it at all.
        - Linear time complexity.
        - Constant space complexity.

numbers = [2,7,11,15], target = 9

"""

from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1

        # possible off-by-one
        while left < right:
            curr_sum = numbers[left] + numbers[right]  # 2 + 7 = 9
            if curr_sum < target:
                left += 1
            elif curr_sum > target:
                right -= 1
            else:
                return [left + 1, right + 1]

        # there is always one solution, so no other returns.


# I would now like to test my solution.
# Are we missing any edge cases? I will now check my solution for syntax errors.
# Apparently none. I shall now submit my solution.
