'''
这段代码是一个二叉树的镜像反转函数。给定一个二叉树的根节点，函数会将该二叉树进行镜像反转，并返回反转后的二叉树的根节点。
代码的步骤如下：
1. 首先定义了一个TreeNode类，用于表示二叉树的节点。节点包含一个值val，以及左右子节点left和right。
2. 然后定义了一个Solution类，其中包含了一个mirrorTree函数，用于实现二叉树的镜像反转。
3. 在mirrorTree函数中，首先判断根节点是否为空。如果为空，则直接返回空节点。
4. 如果根节点不为空，接下来进行镜像反转。通过递归调用mirrorTree函数，分别对根节点的左子节点和右子节点进行镜像反转。
5. 反转的方式是通过交换根节点的左右子节点，即将根节点的左子节点赋值为右子节点，右子节点赋值为左子节点。
6. 最后返回反转后的根节点。
这段代码实现了一个二叉树的镜像反转功能，通过递归的方式对二叉树的每个节点进行处理，将其左右子节点进行交换，从而实现整个二叉树的镜像反转。
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root
        root.left, root.right = self.mirrorTree(root.right), self.mirrorTree(root.left)
        return root