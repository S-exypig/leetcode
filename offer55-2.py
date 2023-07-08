'''
要判断一棵二叉树是否为平衡二叉树，我们可以通过递归的方式来解决。
首先，判断当前节点是否为空，如果为空，则返回True。
然后，分别计算当前节点的左子树和右子树的深度，如果它们的深度差超过1，则返回False。
最后，递归地判断当前节点的左子树和右子树是否为平衡二叉树，如果都是平衡二叉树，则返回True，否则返回False。 
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        if abs(self.getDepth(root.left) - self.getDepth(root.right)) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
            
    def getDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        return max(self.getDepth(root.left), self.getDepth(root.right)) + 1
    
# 优化

class Solution2:
    def depth_and_balance(self,node):
        if node is None:
            return 0, True

        left_depth, left_balance = self.depth_and_balance(node.left)
        right_depth, right_balance = self.depth_and_balance(node.right)
        if not left_balance or not right_balance:
            return -1,False
        cur_depth = max(left_depth, right_depth) + 1
        cur_balance = abs(left_depth - right_depth) <= 1

        return cur_depth, cur_balance

    # 判断二叉树是否为平衡二叉树
    def isBalanced(self,root):
        _, balance = self.depth_and_balance(root)
        return balance
