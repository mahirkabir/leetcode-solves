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
        
        new_node = Node(node.val, [])
        dp[node.val] = new_node
        for neigh in node.neighbors:
            new_node.neighbors.append(self.clone(neigh, dp))
            
        return new_node
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None:
            return node
        return self.clone(node, {})
