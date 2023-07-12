#include <iostream>
using namespace std;
#include <vector>

// 二分查找,数组有序
// 1.寻找第一个大于 target 的元素的下标,不存在返回-1
int upper(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    // 特殊情况
    if (arr[right] <= target) return -1;
    // 迭代法
    // 此模板为找到最后一个target的下一个元素
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// 2.如果数组中存在元素等于
// target，则返回最后一个等于target的元素下标，如果不存在，则返回第一个大于
// target 的元素下标。
int floor_upper(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    // 迭代法
    // 该模板和上一模板本质类似，都是找到target然后再进行操作
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {  // 重点都在于arr[mid] == target时的操作
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
int lower(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
// 4.如果数组中存在元素等于 target，则返回第一个等于target
// 的下标，如果不存在，则返回最后一个小于 target 的元素的下标。
// 如果都不存在，则返回-1
int floor_lower(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    if (arr[left] > target) return -1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            right = mid - 1;
        }
    }
    if (left + 1 < arr.size() && arr[left + 1] == target) return left + 1;
    return left;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 4, 4, 5, 5, 7};
    cout << upper(arr, 3) << endl;        // print 4
    cout << floor_upper(arr, 3) << endl;  // print 4
    cout << lower(arr, 3) << endl;        // print 1
    cout << floor_lower(arr, 3) << endl;  // print 2
    return 0;
}