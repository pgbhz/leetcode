class Solution:
    def addBinary(self, a: str, b: str) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y  # x = 17
            carry = (x & y) << 1  # carry = 0 -> no overlap
            x, y = answer, carry  # magic
        return bin(x)[2:]  # ignore first two digits / chars


"""

    1 1 1 1
    0 0 1 0

    1 1 0 1
    0 1 0 0

    1 0 0 1
    1 0 0 0

    0 0 0 1
  1 0 0 0 0 
  ---------
         17 ok

"""
