// 这段代码是一个用于序列化和反序列化二叉树的类。它使用层序遍历的方式将二叉树转化为一个字符串，并且可以将该字符串转化回原来的二叉树。
// serialize方法接收一个二叉树的根节点作为参数，将二叉树序列化为一个字符串并返回。它使用了一个队列来进行层序遍历。首先将根节点加入队列，然后循环遍历队列中的节点，将节点的值转化为字符串并加入结果字符串中，同时将节点的左右子节点加入队列。如果节点为空，则将"null"加入结果字符串。最后返回结果字符串。
// deserialize方法接收一个字符串作为参数，将该字符串反序列化为一个二叉树并返回。首先判断字符串是否为空，如果为空则返回nullptr。然后使用stringstream将字符串按照逗号分割成一个字符串数组。接着根据数组的第一个元素创建根节点。然后使用队列进行层序遍历，依次取出队列中的节点，根据字符串数组中的元素创建节点的左右子节点，并将其加入队列。最后返回根节点。
// 这段代码使用了队列和字符串流来实现二叉树的序列化和反序列化，是一种常用的实现方式。
#include <iostream>

using namespace std;

#include <queue>
#include <sstream>
#include <string>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;  // 层序遍历
        q.push(root);
        string res = "";  // 此处也可使用sstring装入流中，最后ss.str()即可
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "null,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data.size() == 0) return nullptr;
        queue<TreeNode*> q;
        vector<string> data_vec;
        stringstream ss(data);
        string item;
        while (
            getline(ss, item, ',')) {  // 此处用ss流+getline实现split(,)的功能
            data_vec.push_back(item);
        }
        TreeNode* root =
            new TreeNode(stoi(data_vec[0]));  // stoi将字符串转化为整型
        q.push(root);
        int i = 1;
        // 层序遍历
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (data_vec[i] != "null") {
                node->left = new TreeNode(stoi(data_vec[i]));
                q.push(node->left);
            }
            ++i;
            if (data_vec[i] != "null") {
                node->right = new TreeNode(stoi(data_vec[i]));
                q.push(node->right);
            }
            ++i;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));