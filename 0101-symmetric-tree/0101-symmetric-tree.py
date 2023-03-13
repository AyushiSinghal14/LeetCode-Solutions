# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isSame(root, root)
    
    def isSame(self, num1, num2):
        if not num1 and not num2:
            return True
        elif not num1 or not num2:
            return False
        
        return num1.val == num2.val and self.isSame(num1.right, num2.left) and self.isSame(num1.left, num2.right)
        