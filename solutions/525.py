"""
1. Repeat the question.

    Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0s and 1s.

2. Ask clarifying questions.
3. Work through examples.

    nums = [0,1] -> answer = 2

    nums = [0, 1, 0] -> answer = 2

    nums = [0,1,1,1,1,1,0,0,0] -> answer = 6

4. Brainstorm solutions.

    - What is the brute force?

        Well, we can just test every damn subarray.

        We can use, perhaps, a two pointers approach.
            How? We keep a count. Each time we see a zero, we decrement. Each time we see a one, we increment.
            Each time we change from a positive value to a negative value, we're testing a new array, basically.

5. Implement your solution.

    - I'm doing it, bro! Cool. Done.

6. Test your solution.
"""

from typing import List


class Solution:
    # [0,1,1,1,1,1,0,0,0]
    def findMaxLength(self, nums: List[int]) -> int:
        max_length = 0
        parity_count = 0
        positions = {0: -1}

        for i in range(len(nums)):
            if nums[i] == 0:
                parity_count -= 1
            else:
                parity_count += 1

            if parity_count in positions:
                max_length = max(max_length, (i - positions[parity_count]))
            else:
                positions[parity_count] = i

        return max_length
