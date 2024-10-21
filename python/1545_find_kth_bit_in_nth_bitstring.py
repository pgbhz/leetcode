# O(2**n) space and time, build the string with your own two hands

# class Solution:
#     def findKthBit(self, n: int, k: int) -> str:
#         iteration = 2
#         bs = ["0"]
#         if n == k == 1:
#             return bs[0]
#         while iteration <= n:
#             bs = bs + ["1"] + list(reversed(["0" if b == "1" else "1" for b in bs]))
#             iteration += 1
#             return bs[k - 1]


# O(n) recursion magic.

# class Solution:
#     def findKthBit(self, n: int, k: int) -> str:
#         if n == 1:
#             return "0"

#         s_len = (1 << n) - 1
#         middleIdx = s_len // 2 + 1

#         if k == middleIdx:
#             return "1"  
#         if k < middleIdx:
#             return self.findKthBit(n - 1, k)
#         else:
#             reversed_k_idx = s_len - k + 1
#             bit = self.findKthBit(n - 1, reversed_k_idx)
#             return "1" if bit == "0" else "0"
