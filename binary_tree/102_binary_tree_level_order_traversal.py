# Definition for a binary tree node.
from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = deque([(0, root)])
        levels = []

        # tree -> no cycles brother
        while queue:
            level, curr = queue.popleft()
            if curr is not None:
                if len(levels) == level:
                    levels.append([])
                levels[level].append(curr.val)
                queue.append((level + 1, curr.left))
                queue.append((level + 1, curr.right))

        return levels
