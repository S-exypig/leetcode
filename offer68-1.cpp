// 这段代码实现了在二叉搜索树中找到两个节点的最近公共祖先。代码中提供了两种解法：迭代法和递归法。
// 迭代法中，首先判断根节点和目标节点的大小关系，如果目标节点都比根节点大，则最近公共祖先一定在右子树中；如果目标节点都比根节点小，则最近公共祖先一定在左子树中。如果目标节点一个大一个小，则当前根节点就是最近公共祖先。根据这个规律，通过迭代遍历树，找到最近公共祖先节点，并返回。
// 递归法中，也是通过比较目标节点和根节点的大小关系来确定最近公共祖先的位置。如果目标节点都比根节点大，则递归调用函数，在右子树中继续查找。如果目标节点都比根节点小，则递归调用函数，在左子树中继续查找。如果目标节点一个大一个小，或者其中一个节点就是根节点，则当前根节点就是最近公共祖先。根据这个规律，通过递归遍历树，找到最近公共祖先节点，并返回。
// 在主函数中，首先创建了一个二叉搜索树，并给定了要查找最近公共祖先的两个节点p和q。然后根据选择的解法创建一个Solution或Solution2的实例，并调用lowestCommonAncestor函数来找到最近公共祖先节点。最后输出结果。
// 代码中还包含了释放内存的部分，用于释放创建的二叉树节点的内存。
// 总结来说，这段代码实现了在二叉搜索树中找到两个节点的最近公共祖先，并提供了迭代法和递归法两种解法。

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 迭代法：若两节点与本身相比一大一小，则分别在左右子树，则唯一的公共节点为本身节点；
        //  若都大则在右子树，公共节点最差情况为右子节点；反之，则在左子树，公共节点最差情况为左子节点。
        //  迭代左子节点或右子节点
        if (!root)
            return root;
        TreeNode *cur = root;
        while (cur)
        {
            if (p->val > cur->val && q->val > cur->val)
            {
                cur = cur->right;
            }
            else if (p->val < cur->val && q->val < cur->val)
            {
                cur = cur->left;
            }
            else
                break;
        }
        return cur;
    }
};

class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //递归法：思路同上
        if (!root)
            return root;
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

int main()
{
    // 创建二叉树
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    // Solution solution;
    Solution2 solution;
    TreeNode *p = root->left->right->left;  // 节点3
    TreeNode *q = root->left->left; // 节点0
    TreeNode *result = solution.lowestCommonAncestor(root, p, q);
    cout << "The lowest common ancestor of nodes " << p->val << " and " << q->val << " is: " << result->val << endl;
    // 释放内存
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}