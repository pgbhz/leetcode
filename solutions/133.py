"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

We can do this recursively. DFS style.

"""

from collections import deque
from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def __init__(self):
        self.clones = {}

    def cloneGraph1(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return node

        if node in self.clones:
            return self.clones[node]

        clone_node = Node(node.val, [])  # clone_node points to a new memory address
        self.clones[node] = clone_node  # key is old memory address

        if node.neighbors:
            clone_node.neighbors = [self.cloneGraph(n) for n in node.neighbors]

        return clone_node

    def cloneGraph2(self, node: Optional["Node"]) -> Optional["Node"]:
        if node is None:
            return None

        clones = {}
        queue = deque()

        first_clone = Node(node.val, [])
        clones[node] = first_clone
        queue.appendleft(node)

        while queue:
            curr_node = queue.pop()
            for neighbor in curr_node.neighbors:
                if neighbor not in clones:
                    queue.appendleft(neighbor)
                    clone_node = Node(neighbor.val, [])
                    clones[neighbor] = clone_node

                clones[curr_node].neighbors.append(clones[neighbor])

        return first_clone
