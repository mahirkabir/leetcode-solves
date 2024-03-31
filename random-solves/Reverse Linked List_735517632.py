# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        
        prev = head
        a = head.next
        
        while a != None:
            b = a.next
            a.next = prev
            prev = a
            a = b
        
        head.next = None
        return prev
