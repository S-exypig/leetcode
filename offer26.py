'''
定义了一个Solution类，其中包含一个isSubStructure方法。该方法接受两个参数A和B，分别表示树A和树B的根节点。
该方法的返回值是一个布尔值，表示树B是否是树A的子结构。

在isSubStructure方法中，首先判断A和B是否为空，如果其中任意一个为空，则返回False。然后，调用check方法判断A和B是否相同，
如果相同则返回True。接着，递归调用isSubStructure方法判断A的左子树和B是否相同，以及A的右子树和B是否相同。
最后，如果以上三种情况中有任意一种返回True，则返回True；否则返回False。

在check方法中，首先判断B是否为空，如果为空，则说明B已经遍历完了，返回True。
然后，判断A是否为空，如果为空，则说明A已经遍历完了，返回False。接着，判断A的值是否等于B的值，如果不等，则返回False。
最后，递归调用check方法判断A的左子节点和B的左子节点是否相同，以及A的右子节点和B的右子节点是否相同。
如果以上两种情况都返回True，则返回True；否则返回False。
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if A is None or B is None:
            return False
        return self.check(A, B) or self.isSubStructure(A.left,B) or self.isSubStructure(A.right,B)
    
    def check(self, A: TreeNode, B: TreeNode) -> bool:
        if B is None:
            return True
        if not A or A.val!=B.val:
            return False
        return self.check(A.left, B.left) and self.check(A.right, B.right)