// 这段代码是一个解决二叉树右视图问题的程序。
// 它通过深度优先搜索（DFS）的方式遍历二叉树，先遍历右子树再遍历左子树。
// 在遍历过程中，如果当前层还未插入到结果数组res中（说明当前节点为当层最右节点），则将当前节点的值插入到res中。
// 还可以广度优先（BFS），利用队列进行层序遍历，最后访问的节点即为最右节点
// 时间复杂度都为O（n）,空间复杂度为O（n）
#include <iostream>
using namespace std;
#include <queue>
#include <vector>

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
    vector<int> res;

public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) return {};
        dfs(root, 0);
        return res;
    }
    // 深度优先搜索，中序遍历，先右再左，若当前层还未插入到res中(说明当前节点为当层最右)，则插入
    void dfs(TreeNode *root, int level) {
        if (!root) return;
        if (res.size() == level) {
            res.push_back(root->val);
        }
        dfs(root->right, level + 1);  // 先右
        dfs(root->left, level + 1);   // 再左
    }
};

class Solution2 {
    vector<int> res;

public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) return {};
        bfs(root);
        return res;
    }
    void bfs(TreeNode *root) {
        if (!root) return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (i == size - 1) res.push_back(node->val);
            }
        }
    }
};

int main() {
    // 构造测试用例
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // 调用被测试的函数
    // Solution solution;
    // vector<int> result = solution.rightSideView(root);
    Solution2 solution;
    vector<int> result = solution.rightSideView(root);

    // 打印结果
    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // 释放内存
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}