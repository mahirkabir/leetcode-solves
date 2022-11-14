# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head == None:
            return head
        curr = head
        pre = ListNode()
        head = pre
        # pre.next = curr
        
        while curr != None:
            if curr.val == val:
                # pre.next = curr.next
                curr = curr.next
            else:
                pre.next = curr
                curr = curr.next
                pre = pre.next
            # print(pre)
        pre.next = None
        
        return head.next
