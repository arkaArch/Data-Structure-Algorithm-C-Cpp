#include <vector>
#include <iostream>
using namespace std;

// Find the number in an array that appears once, and other numbers twice.
int single_number(vector<int> &nums) {
    int XOR = 0;
    // a ^ a = 0 and a ^ 0 = a
    for(int num : nums)
        XOR ^= num;
    return XOR;
}

int main() {
    vector<int> nums = {1, 2, 3, 9, 3, 6, 7, 1, 7, 5, 9, 5, 2};
    cout << single_number(nums) << endl;
    return 0;
}
