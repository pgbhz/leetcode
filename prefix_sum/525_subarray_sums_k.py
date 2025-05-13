# class Solution:
#     def subarraySum(self, nums: List[int], k: int) -> int:
#         totalSubarraysWithSumK = 0
#         for i in range(len(nums)):
#             subarraySum = 0
#             for j in range(i, len(nums)):
#                 subarraySum += nums[j]
#                 if subarraySum == k:
#                     totalSubarraysWithSumK += 1
#         return totalSubarraysWithSumK

