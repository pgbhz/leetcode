from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        def backtrack(start):
            if start == len(nums):
                permutations.append(nums[:])

            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[start], nums[i]
                backtrack(start+1)
                nums[start], nums[i] = nums[start], nums[i]

        backtrack(0)
        return permutations

# class Solution:
#     def permute(self, nums: List[int]) -> List[List[int]]:
#         permutations = []
#         permute_recurse(nums, [], permutations)
#         return permutations        

# def permute_recurse(nums: List[int],
#                     permutation: List[int],
#                     permutations: List[List[int]]):
#     # implicit booleaness of lists
#     if not nums:
#         permutations.append(permutation)
#         return
#     else:
#         for num in nums:
#             new_permutation = permutation + [num]
#             nums_without_num = [n for n in nums if n != num]
#             permute_recurse(nums_without_num, new_permutation, permutations)
#     return