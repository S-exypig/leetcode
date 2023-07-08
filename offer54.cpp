// 这段代码的功能是在给定的二叉树中找到第k大的节点值。 
// 代码首先定义了一个二叉树节点的结构体，包含值、左子节点和右子节点。然后定义了一个Solution类，其中有一个成员函数kthLargest，用于找到第k大的节点值。 
// kthLargest函数首先调用了postOrder函数，对二叉树进行倒序的中序遍历。
// 具体来说，先遍历右子树，然后遍历当前节点，最后遍历左子树。在遍历右子树的过程中，每遍历一个节点，将rank值加1。
// 当rank等于k时，说明找到了第k大的节点，将该节点的值赋给res，并返回。在遍历左子树的过程中，同样进行相同的操作。 
// 在主函数中，创建了一个二叉树，并调用了Solution类的kthLargest函数，将要找的第k大的节点值存储在result变量中。最后输出结果。
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
    int kthLargest(TreeNode *root, int k)
    {
        postOrder(root, k);
        return res;
    }
    int res = 0;
    int rank = 0;
    // 中序遍历,因为找第k大，所以需要倒序遍历
    //  先遍历右子树，从右往左数第k大
    void postOrder(TreeNode *root, int k)
    {
        if (root == nullptr)
            return;
        // 遍历右子树，直到达到最深处，即为最大开始往回找
        postOrder(root->right, k);
        ++rank;
        if (rank == k)
        {
            res = root->val;
            return;
        }
        postOrder(root->left, k);
    }
};

int main()
{
    // 创建二叉树
    // TreeNode* root = new TreeNode(5);
    // root->left = new TreeNode(3);
    // root->right = new TreeNode(6);
    // root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    // root->left->left->left = new TreeNode(1);
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution solution;
    int k = 3; // 要找第k大的节点
    int result = solution.kthLargest(root, k);

    cout << "The " << k << "th largest element in the binary tree is: " << result << endl;

    // 释放内存
    // delete root->left->left->left;
    // delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}