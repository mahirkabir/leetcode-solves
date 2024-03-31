# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        
        s = []
        curr = head
        while curr.next != None:
            s.append(curr)
            curr = curr.next
            
        head = curr
        while len(s) != 0:
            top = s.pop()
            top.next = None
            curr.next = top
            curr = curr.next
            
        return head
