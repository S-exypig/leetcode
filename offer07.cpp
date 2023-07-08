// 这段代码实现了根据前序遍历和中序遍历构建二叉树的功能。
// 首先判断前序遍历数组是否为空，如果为空则返回nullptr。然后使用一个unordered_map来存储中序遍历数组中每个元素的索引位置。
// 接下来调用buildTreeHelper函数来递归构建二叉树。
// buildTreeHelper函数的参数包括前序遍历数组、中序遍历数组、前序遍历的起始和结束位置、中序遍历的起始和结束位置。
// 首先判断递归结束的条件，即如果前序遍历的起始位置大于结束位置或者中序遍历的起始位置大于结束位置，则返回nullptr。
// 然后创建一个新的节点，节点的值为前序遍历数组的起始位置对应的值。
// 然后找到该节点在中序遍历数组中的索引位置，计算出左子树的大小和右子树的大小。
// 然后递归构建左子树和右子树，
// 左子树的前序遍历起始位置为prestart+1，结束位置为prestart+leftSize，
// 中序遍历的起始位置为instart，结束位置为rootindex-1；
// 右子树的前序遍历起始位置为prestart+1+leftSize，结束位置为preend，中序遍历的起始位置为rootindex+1，结束位置为inend。
// 最后返回根节点。

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        return buildTreeHelper(preorder,inorder,0,preorder.size()-1,0, inorder.size()-1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
    int prestart, int preend,  int instart, int inend) {
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int rootindex = instart;
        while(rootindex<inend&&inorder[rootindex]!=preorder[prestart]) {
            ++rootindex;
        }
        int leftSize=rootindex-instart;
        int rightSize=inend-rootindex;
        root->left=buildTreeHelper(preorder,inorder,prestart+1,prestart+leftSize,instart,rootindex-1); //左子树
        root->right=buildTreeHelper(preorder,inorder,prestart+1+leftSize,preend,rootindex+1,inend); //右子树
        return root;
    }
};

class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        for(int i=0;i<inorder.size();++i){
            ump[inorder[i]]=i;
        }
        return buildTreeHelper(preorder,inorder,0,preorder.size()-1,0, inorder.size()-1);
    }
    unordered_map<int,int> ump;
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend) {
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int rootindex = ump[root->val];
        int leftSize=rootindex-instart;
        int rightSize=inend-rootindex;
        root->left=buildTreeHelper(preorder,inorder,prestart+1,prestart+leftSize,instart,rootindex-1); //左子树
        root->right=buildTreeHelper(preorder,inorder,prestart+1+leftSize,preend,rootindex+1,inend); //右子树
        return root;
    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // 示例输入
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    // 构建二叉树
    TreeNode* root = s.buildTree(preorder, inorder);

    // 打印二叉树（前序遍历）
    printTree(root);

    return 0;
}