# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        queue = deque([(0, root)])
        levels = {}

        # tree -> no cycles brother
        while len(queue) > 0:
            level, curr = queue.pop()
            if curr is not None:
                if level not in levels:
                    levels[level] = [curr.val]
                else:
                    levels[level].append(curr.val)
                queue.appendleft((level + 1, curr.left))
                queue.appendleft((level + 1, curr.right))

        # extract values in increasing order of keys
        traversal = []
        for level in sorted(levels.keys()):
            traversal.append(levels[level])

        return traversal
