// House Robber.
//
// Cannot rob two adjacent houses. Maximize total robbed.
//
// Time: O(n)
// Space: O(1)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int rob(const std::vector<int>& nums) {
    int prev_one = 0;
    int prev_two = 0;
    for (int x : nums) {
        int new_one = std::max(prev_one, prev_two + x);
        prev_two = prev_one;
        prev_one = new_one;
    }
    return prev_one;
}

int main() {
    assert(rob({1, 2, 3, 1}) == 4);
    assert(rob({2, 7, 9, 3, 1}) == 12);
    assert(rob({}) == 0);
    std::cout << "OK\n";
    return 0;
}
