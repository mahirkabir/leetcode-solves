# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        dict = {}
        curr = head
        
        while curr != None:
            if curr in dict:
                return True
            dict[curr] = True
            curr = curr.next
            
        return False
        
