"""
Can k be greater than the length of the array?
    Yes.
    How do we deal with that?
    if k == len(nums), then it's a full rotation and the array is preserved

We can see that rotating the array is basically reallocating two subarrays of the original array.
As order is preserved, we shift the elements before the pivot to the right, and the two elements after the pivot to the left.
Thus, it is the same as doing a full invert, and then inverting each subarray.
"""


class Solution:

    def reverse(self, nums, left, right):
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

    def rotate(self, nums, k):
        n = len(nums)
        k = k % n
        self.reverse(nums, 0, n - 1)
        self.reverse(nums, 0, k - 1)
        self.reverse(nums, k, n - 1)
