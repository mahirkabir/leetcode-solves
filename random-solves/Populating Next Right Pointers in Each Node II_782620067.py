"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 
        'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return None
        
        level = [[root]]
        queue = [(root, 1)]
        
        while len(queue) > 0:
            u, d = queue.pop(0)
            
            if u.left != None:
                queue.append((u.left, d + 1))
                if len(level) < d + 1:
                    level.append([])
                level[d].append(u.left)
            
            if u.right != None:
                queue.append((u.right, d + 1))
                if len(level) < d + 1:
                    level.append([])
                level[d].append(u.right)
        
        for l in level:
            for i in range(len(l) - 1):
                l[i].next = l[i + 1]
                
        return root
