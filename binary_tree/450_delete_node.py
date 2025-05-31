# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
This sounds a little bit tricky for recursion. What about iteration? Sounds better.
Ok, I feel that for this question we have to have a very good grasp of what a binary search tree is.
Which is all right. We should know our stuff, we are shokunin.

"""


class Solution:
    # one step right and then always left. why?
    def successor(self, root: TreeNode) -> int:
        curr = root.right
        while curr.left:
            curr = curr.left
        return curr.val

    # one step left and then always right. why?
    def predecessor(self, root: TreeNode) -> int:
        curr = root.left
        while curr.right:
            curr = curr.right
        return curr.val

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None

        # delete from the right subtree
        if key > root.val:
            root.right = self.deleteNode(root.right, key)

        # delete from the left subtree
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)

        # delete the current node
        else:
            # the node is a leaf
            if root.left is None and root.right is None:
                root = None

            # the node has right child
            elif root.right:
                root.val = self.successor(root)
                root.right = self.deleteNode(root.right, root.val)

            # the node has left child
            else:
                root.val = self.predecessor(root)
                root.left = self.deleteNode(root.left, root.val)

        return root
