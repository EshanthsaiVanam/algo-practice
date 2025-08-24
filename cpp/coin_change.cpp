// Coin Change.
//
// Given coin denominations and a target amount, return the minimum number of
// coins needed to make the amount, or -1 if not possible.
//
// Time: O(amount * |coins|)
// Space: O(amount)

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

int coinChange(const std::vector<int>& coins, int amount) {
    if (amount < 0) return -1;
    const int sentinel = amount + 1;
    std::vector<int> dp(amount + 1, sentinel);
    dp[0] = 0;
    for (int a = 1; a <= amount; ++a) {
        for (int c : coins) {
            if (a - c >= 0 && dp[a - c] != sentinel) {
                dp[a] = std::min(dp[a], dp[a - c] + 1);
            }
        }
    }
    return dp[amount] == sentinel ? -1 : dp[amount];
}

int main() {
    assert(coinChange({1, 2, 5}, 11) == 3);
    assert(coinChange({2}, 3) == -1);
    assert(coinChange({1}, 0) == 0);
    std::cout << "OK\n";
    return 0;
}
