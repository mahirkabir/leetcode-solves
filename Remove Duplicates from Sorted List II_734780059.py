# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def moveForward(self, head):
        if head.next.val == head.val:
            curr = head.next
            while curr != None and curr.val == head.val:
                curr = curr.next
            
            if curr == None:
                return curr
            else:
                head = curr
                
        return head
    
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        elif head.next == None:
            return head
        
        pre = ListNode(-101)
        pre.next = head
        ret = pre
        curr = head
        
        while curr.next != None:
            if curr.next.val == curr.val:
                curr = self.moveForward(curr)
                pre.next = curr
                if curr == None:
                    return ret.next
                elif curr.next != None:
                    if curr.next.val == curr.val:
                        continue
                else:
                    pre.next = curr
                    pre = curr
            else:
                pre = curr
                curr = curr.next
                
        return ret.next
        
        """if head.next.val == head.val:
            curr = head.next
            while curr != None and curr.val == head.val:
                curr = curr.next
            
            if curr == None:
                return curr
            else:
                head = curr
                
        pre = head
        curr = head.next
        dup = pre.val
        while curr != None and curr.next != None:
            if curr.next.val == curr.val:
                curr = curr.next.next
                pre.next = curr
                dup = curr.val
            else:
                if dup == curr.val:
                    pre.next = curr.next
                    curr = curr.next
                else:
                    pre = curr
                    curr = curr.next
            
        return head"""
