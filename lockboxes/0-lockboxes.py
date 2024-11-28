#!/usr/bin/python3

"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and,
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    unlockedBoxes = set()
    for i, element in enumerate(boxes):
        for box in element:
            if box != i and box < len(boxes):
                unlockedBoxes.add(box)
    unlockedBoxes.add(0)

    for index, unlockedBox in enumerate(unlockedBoxes):
        if index != unlockedBox:
            return False
    return True
