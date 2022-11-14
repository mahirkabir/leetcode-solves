# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        queue = [(root, 0, 0)]
        level = [[0]]
        
        while len(queue) > 0:
            u, d, idx = queue.pop(0)
            d += 1
            
            if len(level) <= d:
                level.append([])
            
            if u.left != None:
                queue.append((u.left, d, (2 * idx) + 1))
                level[d].append((2 * idx) + 1)
                
            if u.right != None:
                queue.append((u.right, d, (2 * idx) + 2))
                level[d].append((2 * idx) + 2)
                
        ans = 0
        for l in level:
            if len(l) > 0:
                ans = max(ans, l[-1] - l[0] + 1)
                
        return ans
