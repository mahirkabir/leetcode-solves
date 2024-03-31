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
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root == None:
            return root
        
        q = []
        q.append(root)
        dis = {}
        
        dis[root] = 1
        levels = {}
        levels[1] = [root]
        
        while len(q) != 0:
            uroot = q.pop(0)
            
            if uroot.left != None:
                vroot = uroot.left
                dis[vroot] = dis[uroot] + 1
                if dis[vroot] not in levels:
                    levels[dis[vroot]] = []
                levels[dis[vroot]].append(vroot)
                q.append(vroot)
                
                vroot = uroot.right
                dis[vroot] = dis[uroot] + 1
                if dis[vroot] not in levels:
                    levels[dis[vroot]] = []
                levels[dis[vroot]].append(vroot)
                q.append(vroot)
                
        for level in levels:
            n = len(levels[level])
            for i in range(0, n - 1):
                levels[level][i].next = levels[level][i + 1]
        return root        
        
