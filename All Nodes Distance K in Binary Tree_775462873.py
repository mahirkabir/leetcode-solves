# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def DFS(self, u, edge):
        if u.val not in edge:
            edge[u.val] = []
        
        v = u.left
        if v != None:
            edge[u.val].append(v.val)
            if v.val not in edge:
                edge[v.val] = []
            edge[v.val].append(u.val)
            # print(v.val, u.val, edge[v.val])
            edge = self.DFS(v, edge)
            
        v = u.right
        if v != None:
            edge[u.val].append(v.val)
            if v.val not in edge:
                edge[v.val] = []
            edge[v.val].append(u.val)
            # print(v.val, u.val, edge[v.val])
            edge = self.DFS(v, edge)
        
        # print(u.val, edge, "*")
        return edge
    
    def BFS(self, s, edge):
        dist = {s: 0}
        
        queue = [s]
        while len(queue) > 0:
            u = queue.pop(0)
            
            for v in edge[u]:
                if v not in dist:
                    dist[v] = dist[u] + 1
                    queue.append(v)
        
        return dist
        
    
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        edge = self.DFS(root, {})
        dist = self.BFS(target.val, edge)
        ans = []
        for u in dist:
            if dist[u] == k:
                ans.append(u)
        return ans
