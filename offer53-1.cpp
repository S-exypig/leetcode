// 实现了一个在有序数组中查找目标值的函数。
// 首先，定义了一个Solution类，其中包含了两个函数leftBound和rightBound，分别用于查找目标值的左边界和右边界。
// 在search函数中，首先判断数组是否为空，如果为空则直接返回0。
// 然后调用leftBound和rightBound函数分别找到目标值的左边界和右边界，并计算区间的长度。
// 如果右边界为-1，则表示目标值不存在，返回0；否则返回右边界减去左边界再加1的结果。
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int left = leftBound(nums, target);
        int right = rightBound(nums, target);
        return right == -1 ? 0 : right - left + 1;
    }
    int leftBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] == target) {
                r = mid - 1;
            }
        }
        if (l < 0 || l >= nums.size()) return -1;
        return nums[l] == target ? l : -1;
    }
    int rightBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] == target) {
                l = mid + 1;
            }
        }
        if (r < 0 || r >= nums.size()) return -1;
        return nums[r] == target ? r : -1;
    }
};

int main() {
    // 创建一个 Solution 对象
    Solution solution;

    // 创建一个测试用例
    vector<int> nums = {1, 2, 2, 2, 2, 2, 4, 5};
    int target = 3;

    // 调用解决方案中的函数进行测试
    int result = solution.search(nums, target);

    // 输出结果
    cout << "结果: " << result << endl;

    return 0;
}