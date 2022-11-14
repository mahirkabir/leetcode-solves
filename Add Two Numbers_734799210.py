# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> 
        Optional[ListNode]:
        if l1 == None:
            return l2
        elif l2 == None:
            return l1
        
        pre = l1
        curr1 = l1
        curr2 = l2
        carry = 0
        
        while curr1 != None and curr2 != None:
            tot = curr1.val + curr2.val + carry
            carry = 0
            if tot >= 10:
                carry = 1
                tot -= 10
                
            curr1.val = tot
            curr2.val = tot
            pre = curr1
            curr1 = curr1.next
            curr2 = curr2.next
            
        if curr2 != None:
            pre.next = curr2
            curr1 = curr2
            
        while curr1 != None:
            tot = curr1.val + carry
            carry = 0
            if tot >= 10:
                carry = 1
                tot -= 10
                
            curr1.val = tot
            pre = curr1
            curr1 = curr1.next
            
        if carry == 1:
            pre.next = ListNode(1)
        
        return l1
        
