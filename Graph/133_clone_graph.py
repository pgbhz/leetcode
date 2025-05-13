"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        
        seen = {}
        def dfs(node):
            copy = Node(node.val)
            seen[copy.val] = copy
            for n in node.neighbors:
                if n.val in seen:
                    copy.neighbors.append(seen[n.val])
                else:
                    copy.neighbors.append(dfs(n))
            return copy

        return dfs(node)

    