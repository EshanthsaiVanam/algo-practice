/**
 * Two Sum.
 *
 * Given an array of integers and a target, return the indices of the two
 * numbers such that they add up to target.
 *
 * Time: O(n)
 * Space: O(n)
 */

export function twoSum(nums: number[], target: number): [number, number] | [] {
    const seen = new Map<number, number>();
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        const j = seen.get(complement);
        if (j !== undefined) {
            return [j, i];
        }
        seen.set(nums[i], i);
    }
    return [];
}

if (require.main === module) {
    const r = twoSum([2, 7, 11, 15], 9);
    if (r.length === 2 && r[0] === 0 && r[1] === 1) {
        console.log("OK");
    } else {
        console.log("FAIL");
        process.exit(1);
    }
}
