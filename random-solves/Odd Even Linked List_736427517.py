# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        
        leftEnd = head
        midStart = head.next
        midEnd = head.next
        rightStart = head.next.next
        
        while rightStart != None: 
            rightRest = rightStart.next # 4.. # None
            leftEnd.next = rightStart # 1->3 # 3->5
            rightStart.next = midStart # 3->2 # 5->2
            midEnd.next = rightRest # 2->4 # 4->None
            # 1->3->2->4 -> 5?
            leftEnd = leftEnd.next # 3 # 5
            midEnd = midEnd.next # 4 # None
            if midEnd == None:
                break
            rightStart = midEnd.next # 5?
            
        return head
        
