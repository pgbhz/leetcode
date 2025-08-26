# class Solution:
#     def mySqrt(self, x: int) -> int:
#         i = 1
#         while True:
#             if x / i < i:
#                 return i-1
#             if x / i == i:
#                 return i
#             i += 1
        
            
# class Solution:
#     def mySqrt(self, x: int) -> int:
#         quotient = x 
#         while True:
#             if quotient * quotient == x:
#                 return quotient
#             if quotient * quotient > x:
#                 quotient //= 2
#             else:
#                 while quotient * quotient <= x:
#                     quotient += 1
#                 return quotient - 1

        
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1:
            return 1
        left = 0
        right = x
        while left < right - 1:
            mid = (left + right) // 2
            product = mid * mid
            if product == x:
                return mid
            elif product < x:
                left = mid
            elif product > x:
                right = mid
        return left

