"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def clone(self, node, dp):
        if node.val in dp:
            return dp[node.val]
        
        ret = Node(node.val, [])
        dp[node.val] = ret
        for n in node.neighbors:
            ret.neighbors.append(self.clone(n, dp))
        
        return dp[node.val]
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None:
            return None
        return self.clone(node, {})
