# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
            
        pre = head
        curr = head.next
        
        while curr != None:
            if curr.val == pre.val:
                pre.next = curr.next
            else:
                pre = pre.next
            curr = curr.next
            
        return head
