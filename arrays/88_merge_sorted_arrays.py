"""
Sorted in non-decreasing order.
We must sort everything inside nums1, in-place.
Can n or m be 0?
nums1 has the size of n in 0s to be filled.

# BRUTE FORCE:
    Put everything of nums2 in the end of nums1 and then sort it.

Let's think of a strategy.

    We keep a pointer to both arrays.
    We keep the current element if its smaller.
    Otherwise we push everything forward and insert it. This is not very efficient.
    Ok, we got the brute force.
    Now, we can copy the nums1, and use the classic two pointer comparison to populate the array.

    Pulo do macaco, always consider the possibility of iterating backwards.
"""

from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1
        p2 = n - 1
        for p in range(len(nums1) - 1, -1, -1):
            if p2 < 0 or (p1 >= 0 and nums1[p1] > nums2[p2]):
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
