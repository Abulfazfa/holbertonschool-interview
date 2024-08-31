#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """Function"""

    count = 0
    for dt in data:
        binary = bin(dt).replace('0b', '').rjust(8, '0')[-8:]
        if count == 0:
            if binary.startswith('110'):
                count = 1
            elif binary.startswith('1110'):
                count = 2
            elif binary.startswith('11110'):
                count = 3
            elif binary.startswith('10'):
                return False
        else:
            if not binary.startswith("10"):
                return False
            count -= 1

    return count == 0
