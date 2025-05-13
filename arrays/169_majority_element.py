"""
Given an array nums of size n, return the majority element.

    - The majority element is the element that appears more than ⌊n / 2⌋ times.

        - element is `majority` if nums.count(element) > floor of n / 2


    - You may assume that the majority element always exists in the array.
        - ok

    - Bro, you forgot the key question:
        - IS THE INPUT ARRAY SORTED ???

    - What is the size of this array?
        - from 1 to 10^4.
        - is 10^8 a reasonable complexity? O(n^2), that is.
            - 10^3 ~ 2^10 -> 10^8 ~ 2^27 ...

    - Some provided test cases:

    Test Case 1

    Input: nums = [3,2,3]
    Output: 3

    Test Case 2

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

    Ok.

    The first solution that comes into mind is to use a hash map storing each element count.

    That would have O(n) space complexity. Is that fine?

    We would like to solve it in linear time and O(1) space.

    How can we keep track of the majority element as we go through the array?
        - wouldn't we need to keep some sort of count hierarchy?
        - how can we know that the majority won't appear sometime in the future?
        - Ok, I've spent time enough thinking about this, let's code it down.

"""

from math import floor
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        element_count = {}

        for num in nums:
            if element_count.get(num, None) is None:
                element_count[num] = 1
            else:
                element_count[num] += 1

        majority_value = floor(len(nums) / 2)
        for element, count in element_count.items():
            if count > majority_value:
                return element


"""
I'd like now to test my code if that's ok.
Nicely played, cowboy.
"""
