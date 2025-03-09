"""Maximum Subarray (Kadane's Algorithm).

Find the contiguous subarray with the largest sum.

Time: O(n)
Space: O(1)
"""


def max_subarray(nums: list[int]) -> int:
    best = current = nums[0]
    for x in nums[1:]:
        current = max(x, current + x)
        best = max(best, current)
    return best


if __name__ == "__main__":
    assert max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
    print("OK")
