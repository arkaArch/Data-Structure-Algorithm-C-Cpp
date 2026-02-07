#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> two_sum_bruteforce(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}

vector<int> two_sum_hash(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++) {
        // Check if complement exist into the map
        int complement = target - nums[i];
        // If key exists in the map → returns an iterator pointing to that element
        // If key does not exist → returns mp.end()
        if(hash.find(complement) != hash.end())
            return {hash[complement], i};
        // Stores the key value pair inside map
        hash[nums[i]] = i;
    }
    // If pair is not found
    return {-1, -1};
}

// If we try to sort the array and then return the indices, we have to create an copy
// of the array to remeber the original position, so there we've need space complexity
// of O(N) and time complexity of O(N) and then to find pair in sorted array we have to
// need O(log N) time complexity. So it's better to use hash.

int main() {
    vector<int> input = {7, 11, 2, 15};
    vector<int> output = two_sum_hash(input, 9);
    cout << output[0] << " " << output[1] << endl;
    return 0;
}
