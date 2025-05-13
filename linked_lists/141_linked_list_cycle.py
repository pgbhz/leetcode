from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    '''fast and slow magic, O(n) time; O(1) space'''
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None or head.next is None:
            return False
        
        fast = head.next
        slow = head

        while fast != slow:
            if fast.next is not None and fast.next.next is not None:
                fast = fast.next.next 
                slow = slow.next
            else:
                return False
        return True



# class Solution:
#     '''dict magic, O(n) time; O(n) space'''
#     def hasCycle(self, head: Optional[ListNode]) -> bool:
#         if head == None:
#             return False
#         visited = {}
#         curr = head
#         while curr != None:
#             if visited.get(curr, False) == True:
#                 return True
#             else:
#                 visited[curr] = True
#             curr = curr.next
#         return False 
    