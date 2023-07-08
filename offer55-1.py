# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
    
if __name__ == '__main__':
    s=Solution()
    root=TreeNode(1)
    root.left=TreeNode(2)
    root.right=TreeNode(3)
    root.left.left=TreeNode(4)
    print(s.maxDepth(root))
