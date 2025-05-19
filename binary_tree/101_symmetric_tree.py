# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional


class Solution:
    def isMirroed(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:  # type: ignore
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        if p.val != q.val:
            return False
        return self.isMirroed(p.left, q.right) and self.isMirroed(p.right, q.left)  # type: ignore

    def isMirroed(self, root: Optional[TreeNode]) -> bool:
        return self.isMirroed(root.left, root.right)  # type: ignore
