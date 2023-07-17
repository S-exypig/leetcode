// n-1:最右边的1变成0，该1右边的0变1
// n&n-1:最右边的1变成0
#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            n &= (n - 1);
            ++res;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(11) << endl << s.hammingWeight(128);  // 3 and 1
    return 0;
}