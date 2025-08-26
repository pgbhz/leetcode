class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n > 0:
            count = count + 1 if n & 1 else count
            n = n >> 1
        return count
