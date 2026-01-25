/*
 * Coin Change.
 *
 * Min coins to make amount, or -1.
 *
 * Time: O(amount * |coins|)
 * Space: O(amount)
 */

import java.util.Arrays;

public class CoinChange {

    public static int coinChange(int[] coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        int sentinel = amount + 1;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, sentinel);
        dp[0] = 0;
        for (int a = 1; a <= amount; a++) {
            for (int c : coins) {
                if (a - c >= 0 && dp[a - c] != sentinel) {
                    dp[a] = Math.min(dp[a], dp[a - c] + 1);
                }
            }
        }
        return dp[amount] == sentinel ? -1 : dp[amount];
    }

    public static void main(String[] args) {
        assert coinChange(new int[] {1, 2, 5}, 11) == 3;
        assert coinChange(new int[] {2}, 3) == -1;
        assert coinChange(new int[] {1}, 0) == 0;
        System.out.println("OK");
    }
}
