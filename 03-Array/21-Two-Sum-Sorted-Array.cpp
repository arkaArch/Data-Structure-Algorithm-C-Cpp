#include <vector>
#include <iostream>
using namespace std;

vector<int> two_sum(vector<int>& nums, int target) {
    int first_index = 0;
    int last_index = nums.size() - 1;
    while(first_index < last_index) {
        int sum = nums[first_index] + nums[last_index]; 
        if(sum == target)
            return {first_index, last_index};
        else if(sum < target)
            first_index++;
        else // sum > target
            last_index--;
    }
    // If not found
    return {-1, -1};
}

int main() {
    vector<int> input = {2, 5, 7, 9, 11, 15};
    vector<int> output = two_sum(input, 22);
    cout << output[0] << " " << output[1] << endl;
    return 0;
}
