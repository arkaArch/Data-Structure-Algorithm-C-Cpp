#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<int>> count_frequencies(vector<int>& nums) {
    unordered_map<int, int> freq;
    // In this map, we store index as key and frequency of 
    // the number in that index/key as value
    for(int num : nums)
        freq[num]++;

    vector<vector<int>> result;
    for(auto &entry : freq) {
        result.push_back({entry.first, entry.second});
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, -6, 2, -6, 2, 4};

    vector<vector<int>> result = count_frequencies(nums);
    for (auto& pair : result)
        cout << "Element: " << pair[0] << "\tFrequency: " << pair[1] << endl;

    return 0;
}
