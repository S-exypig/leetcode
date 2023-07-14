#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0] == 0 ? 1 : 0;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) {
                right = mid - 1;
            } else if (nums[mid] == mid) {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    cout << Solution().missingNumber(arr) << endl;
    return 0;
}