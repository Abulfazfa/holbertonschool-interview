#!/usr/bin/python3

"""
n
"""


def minOperations(n):
    """
    n
    """
    if n <= 1:
        return 0

    operations = 0
    d = 2
    while n > 1:
        while n % d == 0:
            operations += d
            n //= d
        d += 1
    return operations
