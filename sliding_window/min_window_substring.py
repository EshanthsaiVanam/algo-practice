"""Minimum Window Substring.

Smallest window of s containing all chars of t.

Time: O(|s| + |t|)
Space: O(|s| + |t|)
"""

from collections import Counter


def min_window(s: str, t: str) -> str:
    if not s or not t or len(s) < len(t):
        return ""
    need = Counter(t)
    have = {}
    have_count = 0
    target = len(need)

    best_len = float("inf")
    best_range = (0, 0)
    left = 0
    for right, ch in enumerate(s):
        have[ch] = have.get(ch, 0) + 1
        if ch in need and have[ch] == need[ch]:
            have_count += 1
        while have_count == target:
            if right - left + 1 < best_len:
                best_len = right - left + 1
                best_range = (left, right)
            have[s[left]] -= 1
            if s[left] in need and have[s[left]] < need[s[left]]:
                have_count -= 1
            left += 1
    if best_len == float("inf"):
        return ""
    l, r = best_range
    return s[l:r + 1]


if __name__ == "__main__":
    assert min_window("ADOBECODEBANC", "ABC") == "BANC"
    print("OK")
