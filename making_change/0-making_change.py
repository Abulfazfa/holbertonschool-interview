#!/usr/bin/python3
"""
making change
"""


def makeChange(coins, total):
    """Given a pile of coins of different values,
     determine the fewest number
    of coins needed to meet a given amount total.
    """
    if total < 1:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    if dp[total] == float('inf'):
        return -1

    return dp[total]
