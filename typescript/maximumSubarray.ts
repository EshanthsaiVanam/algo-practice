/**
 * Maximum Subarray (Kadane's Algorithm).
 *
 * Find the contiguous subarray with the largest sum.
 *
 * Time: O(n)
 * Space: O(1)
 */

export function maxSubarray(nums: number[]): number {
    if (nums.length === 0) return 0;
    let best = nums[0];
    let current = nums[0];
    for (let i = 1; i < nums.length; i++) {
        current = Math.max(nums[i], current + nums[i]);
        best = Math.max(best, current);
    }
    return best;
}

if (require.main === module) {
    console.assert(maxSubarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) === 6);
    console.assert(maxSubarray([1]) === 1);
    console.assert(maxSubarray([5, 4, -1, 7, 8]) === 23);
    console.log("OK");
}
