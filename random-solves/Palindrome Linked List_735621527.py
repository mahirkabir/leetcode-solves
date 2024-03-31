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
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        tot = 0
        curr = head
        while curr != None:
            curr = curr.next
            tot += 1
            
        newtot = 1
        prev = head
        curr = head
        while newtot * 2 <= tot:
            curr = curr.next
            newtot += 1
        if tot % 2 == 1:
            curr = curr.next
        
        newcurr = self.reverseList(curr)
        
        while newcurr != None:
            if prev.val != newcurr.val:
                return False
            prev = prev.next
            newcurr = newcurr.next
            
        return True
        
