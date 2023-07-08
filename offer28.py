'''
这段代码中，定义了一个 Solution 类，其中包含了一个 isSymmetric 函数，用于判断二叉树是否对称。函数接收一个二叉树的根节点作为参数，返回一个布尔值，表示二叉树是否对称。 

在 isSymmetric 函数中，首先判断根节点是否为空。如果为空，则直接返回 True ，因为空树被认为是对称的。 

如果根节点不为空，则调用 checkSymmetry 函数来判断左右子树是否对称。 checkSymmetry 函数接收左右子树的根节点作为参数，返回一个布尔值，表示左右子树是否对称。 

在 checkSymmetry 函数中，有以下几种情况需要考虑： 
- 如果左右子树的根节点都为空，说明当前节点是叶子节点，对称性成立，返回 True 。 
- 如果左右子树的根节点只有一个为空，说明左右子树结构不对称，返回 False 。 
- 如果左右子树的根节点的值不相等，说明左右子树的节点值不对称，返回 False 。 
- 否则，递归地判断左子树的左节点和右子树的右节点是否对称，以及左子树的右节点和右子树的左节点是否对称。如果都对称，则返回 True ，否则返回 False 。 

通过递归地判断二叉树的左右子树是否对称，从而判断整个二叉树是否对称。
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.check(root.left, root.right)
    
    def check(self, left: TreeNode, right: TreeNode) -> bool:
        if left is None and right is None:
            return True
        if left is None or right is None or left.val != right.val:
            return False
        return self.check(left.left, right.right) and self.check(left.right, right.left)