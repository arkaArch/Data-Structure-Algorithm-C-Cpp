#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// The majority element of an array is an element that appears more than n/2 times 
// in the array.
// You may assume that the majority element always exists in the array.

int majority_element_brute_force(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        int freq = 1;   // frequency of nums[i]
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] == nums[j])
                freq++;
        }
        if(freq > nums.size() / 2)
            return nums[i];
    }
    return -1;      // Majority element not found
}

int majority_element_hash(vector<int>& nums) {
    unordered_map<int, int> hash;
    // In this map, we store index as key and frequency of 
    // the number in that index/key as value
    for(int num : nums)
        hash[num]++;
    
    for(const auto& entry : hash) {
        if(entry.second > nums.size() / 2)
            return entry.first;
    }
    return -1;  // Majority element not found
}

/* Boyer-Moore Voting algorithm:
 * Since the majority element appears more than n/2 times, its frequency is greater 
 * than the combined frequency of all the other elements. So, if we rank the occurance 
 * of the majority element as +1 and the occurance of any other element as -1, then the 
 * overall sum of these markings would definitely be greater than zero. */
int majority_element_opt(vector<int>& nums) {
    int count = 0, element = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(count == 0) {
            count = 1;
            element = nums[i];
        } else if(element == nums[i])
            count++;
        else if(element != nums[i])
            count--;
    }
    return element;
}

int main() {
    vector<int> nums = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    vector<int> nums2 = {2,1,0,2,2,1, 9, 0, 3, 6, 9, 5, -4, -7};
    cout << majority_element_opt(nums2) << endl;
    return 0;
}
