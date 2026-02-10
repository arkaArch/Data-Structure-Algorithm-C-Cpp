#include <vector>
#include <iostream>
using namespace std;

int find_max_consecutive_ones(vector<int>& nums) {
    int count = 0;
    int max_count = 0;
    for(int num : nums) {
        if(num == 1)
            count++;
        else
            count = 0;

        if(count > max_count)
            max_count = count;
    }
    return max_count;
}

int main() {
    vector<int> nums = {1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0};
    cout << find_max_consecutive_ones(nums) << endl;
    return 0;
}
