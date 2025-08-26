from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        # verify rows
        for row in board:
            seen = set()
            for digit in row:
                if digit in seen and digit != ".":
                    return False
                seen.add(digit)

        # verify columns
        for j in range(len(board[0])):
            seen = set()
            for i in range(len(board)):
                digit = board[i][j]
                if digit in seen and digit != ".":
                    return False
                seen.add(digit)

        # verify 3x3 submatrices
        limits = [(0, 3), (3, 6), (6, 9)]
        for i_start, i_end in limits:
            for j_start, j_end in limits:
                seen = set()
                for i in range(i_start, i_end):
                    for j in range(j_start, j_end):
                        digit = board[i][j]
                        if digit in seen and digit != ".":
                            return False
                        seen.add(digit)

        return True
