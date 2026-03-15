/**
 * Coin Change.
 *
 * Given coin denominations and a target amount, return the minimum number of
 * coins needed to make the amount, or -1 if not possible.
 *
 * Time: O(amount * |coins|)
 * Space: O(amount)
 */

export function coinChange(coins: number[], amount: number): number {
    if (amount < 0) return -1;
    const sentinel = amount + 1;
    const dp: number[] = new Array(amount + 1).fill(sentinel);
    dp[0] = 0;
    for (let a = 1; a <= amount; a++) {
        for (const c of coins) {
            if (a - c >= 0 && dp[a - c] !== sentinel) {
                dp[a] = Math.min(dp[a], dp[a - c] + 1);
            }
        }
    }
    return dp[amount] === sentinel ? -1 : dp[amount];
}

if (require.main === module) {
    console.assert(coinChange([1, 2, 5], 11) === 3);
    console.assert(coinChange([2], 3) === -1);
    console.assert(coinChange([1], 0) === 0);
    console.log("OK");
}
