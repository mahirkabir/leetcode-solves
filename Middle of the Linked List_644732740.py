# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = 0
        curr = head
        while(curr != None):
            cnt += 1
            curr = curr.next
            
        if cnt % 2 == 0:
            cnt = (cnt / 2) + 1
        else:
            cnt = (cnt + 1) / 2
        
        cnt -= 1
        while cnt > 0:
            head = head.next
            cnt -= 1
            
        return head
