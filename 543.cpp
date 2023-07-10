// 求二叉树的最大直径，递归的思想。某树的最大直径为其左右子树的最大直径或该节点左右子树的深度之和

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        depth(root);
        return res;
    }
    int depth(TreeNode *root) {
        if (!root) return 0;
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        // 后序遍历位置，该节点最大直径为左右孩子的最大直径或左子树的深度+右子树的深度
        res = max(res, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }
};