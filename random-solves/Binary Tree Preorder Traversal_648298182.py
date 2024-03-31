# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root == None:
            return root
        
        s = []
        s.append(root)
        
        ans = []
        while len(s) != 0:
            top = s.pop()
            ans.append(top.val)
            
                
            if top.right != None:
                s.append(top.right)
                
            if top.left != None:
                s.append(top.left)
        return ans
