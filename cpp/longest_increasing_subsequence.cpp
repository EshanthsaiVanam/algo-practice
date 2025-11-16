// Longest Increasing Subsequence.
//
// Approach: patience sorting with binary search.
// Time: O(n log n)
// Space: O(n)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> tails;
    tails.reserve(nums.size());
    for (int x : nums) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    return static_cast<int>(tails.size());
}

int main() {
    assert(lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(lengthOfLIS({0, 1, 0, 3, 2, 3}) == 4);
    assert(lengthOfLIS({7, 7, 7, 7, 7}) == 1);
    assert(lengthOfLIS({}) == 0);
    std::cout << "OK\n";
    return 0;
}
