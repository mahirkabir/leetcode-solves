# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        
        prev = head
        curr = head.next
        
        while(curr != None):
            while curr != None and curr.val == prev.val:
                curr = curr.next
            
            prev.next = curr
            prev = prev.next
            if prev != None:
                curr = prev.next
            else:
                break
                
        return head
