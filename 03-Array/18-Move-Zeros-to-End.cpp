#include <vector>
#include <iostream>
using namespace std;

// Move all 0's to the end of it while maintaining the relative 
// order of the non-zero elements.
void move_zeroes(vector<int>& nums) {
    for(int i = 0, j = 0; i < nums.size(); i++) {
        // j pointing to the element zero
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    move_zeroes(arr);
    for(int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}

