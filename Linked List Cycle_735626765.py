# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head == None or head.next == None:
            return False
        
        int_min = -1000000
        curr = head
        while curr != None:
            if curr.next == None:
                return False
            if curr.next.val == int_min:
                return True
            curr.val = int_min
            curr = curr.next
