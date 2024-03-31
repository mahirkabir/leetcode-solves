# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def get_size(self, head) -> int:
        cnt = 0
        while head != None:
            head = head.next
            cnt += 1
        return cnt
    
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> 
        Optional[ListNode]:
        sz = self.get_size(head)
        
        if sz == n:
            return head.next
        
        keep = sz - n - 1
        curr = head
        
        while keep > 0:
            curr = curr.next
            keep -= 1
        
        if curr == None:
            return None
        elif curr.next == None:
            return None
        curr.next = curr.next.next
        return head
