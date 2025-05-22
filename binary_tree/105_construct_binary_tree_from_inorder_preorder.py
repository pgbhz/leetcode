# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
"""
How can I make use of both arrays?

Can I use like a hash map to store parenthood?

The first element of preorder traversal is the tree's root.

After we find this element in the inorder traversal, every element to its left is the
left subtree and the same goes for the elements to the right.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
"""


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None

        root = preorder[0]
        root_node = TreeNode(root)
        root_idx_inorder = inorder.index(root)

        inorder_left_subtree = inorder[:root_idx_inorder]
        inorder_right_subtree = inorder[root_idx_inorder + 1 :]

        len_left_subtree = len(inorder_left_subtree)
        root_node.left = self.buildTree(
            preorder[1 : (1 + len_left_subtree)], inorder[:root_idx_inorder]
        )
        root_node.right = self.buildTree(
            preorder[(1 + len_left_subtree) :], inorder[(root_idx_inorder + 1) :]
        )

        return root_node
