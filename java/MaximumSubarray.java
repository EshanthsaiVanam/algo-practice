/*
 * Maximum Subarray (Kadane's Algorithm).
 *
 * Find the contiguous subarray with the largest sum.
 *
 * Time: O(n)
 * Space: O(1)
 */

public class MaximumSubarray {

    public static int maxSubarray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int best = nums[0];
        int current = nums[0];
        for (int i = 1; i < nums.length; i++) {
            current = Math.max(nums[i], current + nums[i]);
            best = Math.max(best, current);
        }
        return best;
    }

    public static void main(String[] args) {
        assert maxSubarray(new int[] {-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6;
        assert maxSubarray(new int[] {1}) == 1;
        assert maxSubarray(new int[] {5, 4, -1, 7, 8}) == 23;
        System.out.println("OK");
    }
}
