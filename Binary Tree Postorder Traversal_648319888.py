# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorder(self, root, ans):
        if root == None:
            return
        if root.left != None:
            self.postorder(root.left, ans)
        if root.right != None:
            self.postorder(root.right, ans)
        ans.append(root.val)
        
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.postorder(root, ans)
        return ans
