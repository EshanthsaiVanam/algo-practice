// Two Sum.
//
// Given an array of integers and target, return indices of the two numbers
// that sum to target.
//
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int complement = target - nums[i];
        auto it = seen.find(complement);
        if (it != seen.end()) {
            return {it->second, i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    auto result = twoSum({2, 7, 11, 15}, 9);
    if (result.size() == 2 && result[0] == 0 && result[1] == 1) {
        std::cout << "OK\n";
    } else {
        std::cout << "FAIL\n";
        return 1;
    }
    return 0;
}
