"""Two Sum.

Given an array of integers and target, return indices of the two numbers
that sum to target.

Time: O(n)
Space: O(n)
"""


def two_sum(nums: list[int], target: int) -> list[int]:
    seen: dict[int, int] = {}
    for i, x in enumerate(nums):
        complement = target - x
        if complement in seen:
            return [seen[complement], i]
        seen[x] = i
    return []


if __name__ == "__main__":
    assert two_sum([2, 7, 11, 15], 9) == [0, 1]
    print("OK")
