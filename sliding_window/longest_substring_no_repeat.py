"""Longest Substring Without Repeating Characters.

Time: O(n)
Space: O(min(n, alphabet))
"""


def length_of_longest_substring(s: str) -> int:
    seen = set()
    left = 0
    best = 0
    for right, ch in enumerate(s):
        while ch in seen:
            seen.remove(s[left])
            left += 1
        seen.add(ch)
        best = max(best, right - left + 1)
    return best


if __name__ == "__main__":
    assert length_of_longest_substring("abcabcbb") == 3
    print("OK")
