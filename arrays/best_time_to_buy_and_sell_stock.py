"""Best Time to Buy and Sell Stock.

Maximize profit by choosing one buy day and one sell day after.

Time: O(n)
Space: O(1)
"""


def max_profit(prices: list[int]) -> int:
    min_price = float("inf")
    best = 0
    for p in prices:
        if p < min_price:
            min_price = p
        elif p - min_price > best:
            best = p - min_price
    return best


if __name__ == "__main__":
    assert max_profit([7, 1, 5, 3, 6, 4]) == 5
    assert max_profit([7, 6, 4, 3, 1]) == 0
    print("OK")
