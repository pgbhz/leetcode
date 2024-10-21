# class Solution:
#     def maximumSwap(self, num: int) -> int:
#         digits = [int(d) for d in str(num)]
#         greatestNextDigit = [-1] * len(digits)
#         stack = []
#         for i, d in enumerate(digits):
#             while stack and digits[stack[-1]] < d:
#                 greatestNextDigit[stack.pop()] = i
#             stack.append(i)
#         print(greatestNextDigit)
#         for i, greatestNextIdx in enumerate(greatestNextDigit):
#             digit = digits[i]
#             greatestNext = digits[greatestNextIdx]
#             if greatestNextIdx != -1:
#                 digits[i], digits[greatestNextIdx] = digits[greatestNextIdx], digits[i]
#                 break
#         print(num)
#         print(digits)
#         return int(''.join([str(d) for d in digits]))

class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = [int(d) for d in str(num)]
        greatestNxtIdx = [-1] * len(digits)
        maxSeenIdx = -1
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] > digits[maxSeenIdx]:
                maxSeenIdx = i
            greatestNxtIdx[i] = maxSeenIdx
        for i in range(len(digits)):
            if digits[i] < digits[greatestNxtIdx[i]]:
                digits[i], digits[greatestNxtIdx[i]] = digits[greatestNxtIdx[i]], digits[i]
                break
        return int(''.join([str(d) for d in digits]))