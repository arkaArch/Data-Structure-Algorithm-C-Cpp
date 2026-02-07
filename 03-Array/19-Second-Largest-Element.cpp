#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int secondLargestElement(vector<int>& nums) {
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    // If array has 1 element, there will be no second largest
    if(nums.size() < 2)
        return -1;

    for(int num : nums) {
        if(num > largest) {
            second_largest = largest;
            largest = num;
        }
        else if(num > second_largest && num < largest)
            second_largest = num;
    }
    return second_largest == INT_MIN ? -1 : second_largest;
}

int main() {
    vector<int> nums = {1, 2, 4, 6, 7, 5};
    cout << "Second largest: " << secondLargestElement(nums) << endl;
    return 0;
}
