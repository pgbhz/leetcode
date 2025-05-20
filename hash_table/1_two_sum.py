from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        """
        idxes = {}
        for i, n in enumerate(nums):
            k = target - n
            if k in idxes:
                return [i, idxes[k]]
            else:
                idxes[n] = i
