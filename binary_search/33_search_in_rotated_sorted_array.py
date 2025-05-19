"""
- array is sorted in ascending order
- array is POSSIBLY rotated, at unknown pivot index `k`. what is rotated?

    [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

- all values are unique
- we're looking for a O(log n) complexity here
    - that sounds like binary search

- how can we do binary search for this?
    - unrotate the array
    - do modified binary search

- we do not know k, but we can find it linearly
- should we find k and work with it? or "fix" the array?
    - what is the complexity of fixing the array?
    - is it ok if we fix it?
- do we always have the target? no. in that case, return -1
- i think it will be easier if we just rotate it back. we need O(n) complexity for that.
- do we want the target idx in the rotated or unrotated array? rotated

- key solution idea for this two binary search approach:
    - pivot will be the first element smaller than the last element.
    - why do we need a binary search for that? because we want solution in 0(log n)
    - oh god, now I realize that my previous solution would be O(n)...
"""

from typing import List


class Solution:
    def binarySearch(self, nums, target, left, right):
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1

    def findPivot(self, nums):
        n = len(nums)
        left, right = 0, n - 1
        while left <= right:
            mid = (left + right) // 2

            # we want to find the first element that is greater than the last element of the array
            # our pivot will be to the right of that element
            if nums[mid] > nums[-1]:
                left = mid + 1
            else:
                right = mid - 1
        return left

    def search(self, nums: List[int], target: int) -> int:
        left = self.findPivot(nums)
        right = len(nums) - 1
        l_idx = self.binarySearch(nums, target, 0, left - 1)
        r_idx = self.binarySearch(nums, target, left, right)
        if l_idx == r_idx:
            return -1
        return l_idx if l_idx != -1 else r_idx
