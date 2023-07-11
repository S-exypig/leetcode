#include <iostream>
using namespace std;
#include <vector>

// 二分查找,数组有序
// 1.寻找第一个大于 target 的元素的下标,不存在返回-1
int upper(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    // 迭代法
    while (left <= right) {  // 先找target
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {  // 找到target后找第一个大的元素
            int res = mid;
            while (res <= arr.size() - 1) {
                if (arr[res] > target) {
                    return res;
                }
                res++;
            }
            return -1;
        }
    }
    return -1;
}

// 2.如果数组中存在元素等于
// target，则返回最后一个等于target的元素下标，如果不存在，则返回第一个大于
// target 的元素下标。
int floor_upper(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    // 迭代法
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            int res = right;
            while (res > mid) {
                if (arr[res] == target) return res;
                --res;
            }
            return mid;
        }
    }
    return left ? left < arr.size() : -1;
}
// 3.寻找最后一个小于 target 的元素的下标
// 如果都不存在，则返回-1
int lower(vector<int>& arr, int target) {}
// 4.如果数组中存在元素等于 target，则返回第一个等于target
// 的下标，如果不存在，则返回最后一个小于 target 的元素的下标。
// 如果都不存在，则返回-1
int floor_lower(vector<int>& arr, int target) {}

int main() {
    vector<int> arr = {1, 2, 3, 3, 4, 4, 5, 5, 7};
    cout << upper(arr, 3) << endl;        // print 4
    cout << floor_upper(arr, 3) << endl;  // print 4
    return 0;
}