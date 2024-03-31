# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def merge(self, root1, root2):
        root1.val += root2.val
        
        if root2.left != None:
            if root1.left != None:
                self.merge(root1.left, root2.left)
            else:
                root1.left = root2.left
        
        if root2.right != None:
            if root1.right != None:
                self.merge(root1.right, root2.right)
            else:
                root1.right = root2.right
    
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> 
        Optional[TreeNode]:
        if root1 == None:
            return root2
        elif root2 == None:
            return root1
        
        ans = TreeNode()
        ans = root1
        
        self.merge(root1, root2)
        
        return ans
