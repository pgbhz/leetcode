class Solution:
    """
    😂
    """

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
