// 函数的目标是验证给定的后序遍历序列是否是一个二叉搜索树的后序遍历序列。 
// 函数首先检查postorder数组的大小，如果为0，则返回true。 
// 然后调用辅助函数check来进行验证。check函数接受三个参数，即postorder数组、左边界l和右边界r。 
// 在check函数中，首先判断左边界是否大于等于右边界，如果是，则返回true。 
// 然后，获取当前子树的根节点的值，即postorder[r]。 
// 接下来，使用两个指针i和j来遍历数组。指针i从左边界开始，向右移动，直到找到第一个大于根节点值的元素。指针j从指针i的位置开始，向右移动，直到找到第一个小于根节点值的元素。 
// 如果指针j没有达到右边界，则说明存在一个大于根节点值的元素，不满足二叉搜索树的性质，返回false。 
// 最后，递归调用check函数来验证左子树和右子树是否满足二叉搜索树的性质，即调用check(postorder, l, i-1)和check(postorder, i, j-1)。 
// 如果左子树和右子树都满足二叉搜索树的性质，则返回true，否则返回false。 
// 整个函数的时间复杂度为O(nlogn)，其中n为数组postorder的长度。

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()==0) return true;
        return check(postorder,0,postorder.size()-1);
    }
    bool check(vector<int>& postorder,int l,int r) {
        if(l>=r) return true;
        int root=postorder[r];
        int i=l;
        while(i<r&&postorder[i]<root) ++i;
        int j=i;
        while(j<r&&postorder[j]>root) ++j;
        if(j<r) return false;
        return check(postorder,l,i-1)&&check(postorder,i,j-1);
    }
};

int main() {
    vector<int> postorder={1,2,5,10,6,9,4,3};
    Solution s;
    cout<<s.verifyPostorder(postorder);
    return 0;
}

