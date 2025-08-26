"""
prefix or suffix ...
no division operator
extra space is allowed
what extra space do we need? another array, a hash map?
we can have like two extra arrays

    - a regular prefix multiplication array
    - an inverted prefix multiplication array

a dumb get-done is, idk

Input:  [1,2,3,4]

         1  2  3    4
        [1, 2, 6,  24]
        [24, 24, 12, 4]     that doesn't tell much, does it?
                            it does. i think i got this.

        calculate the prefix array
        invert the array, calculate the second prefix array, invert it again, that will be the suffix array
        for every position i, except the first and last, the product of array except self is
            the product of prefix[i-1] with suffix[i+1]
        otherwise,
        first position = suffix[i+1]
        last position = prefix[i-1]

        [1, 2, 6, 24]
        [24, 6, 2, 1]

Output: [24,12,8,6]

"""

from typing import List


class Solution1:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [n for n in nums]
        suffix = [n for n in nums][::-1]
        for i in range(1, len(prefix)):
            prefix[i] *= prefix[i - 1]
            suffix[i] *= suffix[i - 1]
        suffix = suffix[::-1]

        product = [0] * len(nums)
        product[0] = suffix[1]
        product[len(nums) - 1] = prefix[len(nums) - 2]
        for i in range(1, len(nums) - 1):
            product[i] = prefix[i - 1] * suffix[i + 1]
        return product


class Solution2:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [1] * n
        suffix = [1] * n
        product = [0] * n

        for i in range(1, n):
            prefix[i] = prefix[i - 1] * nums[i - 1]

        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] * nums[i + 1]

        for i in range(n):
            product[i] = prefix[i] * suffix[i]

        return product


class GigaChad:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        output = [1] * n

        for i in range(1, n):
            output[i] = output[i - 1] * nums[i - 1]

        right_product = 1
        for i in range(n - 1, -1, -1):
            output[i] *= right_product
            right_product *= nums[i]

        return output
