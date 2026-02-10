#include <iostream>
#include <vector>
using namespace std;

void sort_one_two_three_two_pass(vector<int>& nums) {
    int p = 0;
    // Sort Zeros
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            swap(nums[i], nums[p]);
            p++;
        }
    }
    // Sort Ones
    for(int i = p; i < nums.size(); i++) {
        if(nums[i] == 1) {
            swap(nums[i], nums[p]);
            p++;
        }
    }
}

void sort_one_two_three_one_pass(vector<int>& nums) {
    // We take low pointer for zero, mid for 1 and high for two
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while(mid < high) {
        if(nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        } else if(nums[mid] == 1) {
            mid++;
        } else {    // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }

}
int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sort_one_two_three_one_pass(nums);
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
