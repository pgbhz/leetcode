"""
We want to contain the most water.
Do we need to calculate area, or can we just slide ahead?
Initial logic:
    we want the highest wall to the left
    we want the highest wall to the right

Constraints:

    n >= 2 : we have at least two walls

We make a function to calculate the area.
We update our walls accordingly.

The brute force is obvious:
    for each wall to the left, find the wall to the right that maximizes area
    that gives us O(n^2)

I've made two stupid mistakes due to menosprezar o problema:
    - calculate area by dividing length by height. wtf ?????
    - set the container height as max instead of min of the two heights. that's stupid...
"""

from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        max_area = 0
        while l < r:
            max_area = max(max_area, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return max_area
