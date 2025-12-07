"""House Robber.

Cannot rob two adjacent houses.

Time: O(n)
Space: O(1)
"""


def rob(nums: list[int]) -> int:
    prev_one = prev_two = 0
    for x in nums:
        prev_one, prev_two = max(prev_one, prev_two + x), prev_one
    return prev_one


if __name__ == "__main__":
    assert rob([1, 2, 3, 1]) == 4
    print("OK")
