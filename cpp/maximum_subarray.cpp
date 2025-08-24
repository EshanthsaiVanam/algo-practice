// Maximum Subarray (Kadane's Algorithm).
//
// Find the contiguous subarray with the largest sum.
//
// Time: O(n)
// Space: O(1)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int maxSubarray(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int best = nums[0];
    int current = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        current = std::max(nums[i], current + nums[i]);
        best = std::max(best, current);
    }
    return best;
}

int main() {
    assert(maxSubarray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
    assert(maxSubarray({1}) == 1);
    assert(maxSubarray({5, 4, -1, 7, 8}) == 23);
    std::cout << "OK\n";
    return 0;
}
