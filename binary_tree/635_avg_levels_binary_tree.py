# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
We want average of levels in Binary Tree.
[avg1, avg2, ....]

How can we get all the values of level in Binary Tree?
Well, in general, we can use something like a map to index every node by its level.
And then, we go through every node in that key and take the average.
Can we make it simpler? Can we be more efficient? I'm not sure.
"""


from collections import defaultdict, deque
from typing import List, Optional


class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        levels = defaultdict(list)
        enqueued = set([root])
        queue = deque([(root, 0)])

        while queue:
            node, level = queue.popleft()
            levels[level].append(node.val)

            if node.left and node.left not in enqueued:
                enqueued.add(node.left)
                queue.append((node.left, level + 1))

            if node.right and node.right not in enqueued:
                enqueued.add(node.right)
                queue.append((node.right, level + 1))

        avg_levels = []
        for level in sorted(levels.keys()):
            avg = 0
            for val in levels[level]:
                avg += val
            avg /= len(levels[level])
            avg_levels.append(avg)
        return avg_levels
