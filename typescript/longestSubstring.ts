/**
 * Longest Substring Without Repeating Characters.
 *
 * Sliding window approach.
 *
 * Time: O(n)
 * Space: O(min(n, alphabet))
 */

export function lengthOfLongestSubstring(s: string): number {
    const seen = new Set<string>();
    let left = 0;
    let best = 0;
    for (let right = 0; right < s.length; right++) {
        const ch = s[right];
        while (seen.has(ch)) {
            seen.delete(s[left]);
            left++;
        }
        seen.add(ch);
        best = Math.max(best, right - left + 1);
    }
    return best;
}

if (require.main === module) {
    console.assert(lengthOfLongestSubstring("abcabcbb") === 3);
    console.assert(lengthOfLongestSubstring("bbbbb") === 1);
    console.assert(lengthOfLongestSubstring("pwwkew") === 3);
    console.log("OK");
}
