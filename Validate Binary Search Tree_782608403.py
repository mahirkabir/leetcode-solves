# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST_(self, root, lo, hi):
        if root == None:
            return True
        
        ret = True
        if root.left != None:
            ret &= (root.val > root.left.val and root.left.val > lo)
            if ret:
                ret &= self.isValidBST_(root.left, lo, root.val)
        
        if ret and root.right != None:
            ret &= (root.right.val > root.val and root.right.val < hi)
            if ret:
                ret &= self.isValidBST_(root.right, root.val, hi)
        
        return ret
        
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.isValidBST_(root, - (2 ** 31) - 2, (2 ** 31) + 2)
