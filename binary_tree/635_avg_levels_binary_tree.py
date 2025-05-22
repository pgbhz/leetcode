# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
Average of levels in Binary Tree.
Returns [avg1, avg2, ...] where each avg is the average of all node values at that level.

This solution uses a standard level-order traversal (BFS) approach to process the tree
level by level, calculating averages as we go.
"""


from collections import deque
from typing import List, Optional


class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        if not root:
            return []

        result = []
        queue = deque([root])

        # Level order traversal
        while queue:
            level_size = len(queue)
            level_sum = 0

            # Process all nodes at current level
            for _ in range(level_size):
                node = queue.popleft()
                level_sum += node.val

                # Add children to queue
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            # Calculate average for current level
            result.append(level_sum / level_size)

        return result
