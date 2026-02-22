/*
 * House Robber.
 *
 * Cannot rob two adjacent houses. Maximize total robbed.
 *
 * Time: O(n)
 * Space: O(1)
 */

public class HouseRobber {

    public static int rob(int[] nums) {
        int prevOne = 0;
        int prevTwo = 0;
        for (int x : nums) {
            int newOne = Math.max(prevOne, prevTwo + x);
            prevTwo = prevOne;
            prevOne = newOne;
        }
        return prevOne;
    }

    public static void main(String[] args) {
        assert rob(new int[] {1, 2, 3, 1}) == 4;
        assert rob(new int[] {2, 7, 9, 3, 1}) == 12;
        assert rob(new int[] {}) == 0;
        System.out.println("OK");
    }
}
