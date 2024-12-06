#!/usr/bin/python3

"""Input stats"""

import sys
import re

logs = 0
total_size = 0
status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

def print_statistics(statuses, total):
    print("File size: {}".format(total))
    for key, value in sorted(statuses.items()):
        if value != 0:
            print("{}: {}".format(key, value))

try:
    # Check if stdin has data
    if sys.stdin.isatty():
        # If running interactively or without input, exit
        print("No input provided", file=sys.stderr)
        sys.exit(0)
        
    for line in sys.stdin:
        try:
            logs += 1
            parts = line.rstrip().split(" ")
            if len(parts) < 2:
                continue
            total_size += int(parts[-1])  # Last part is file size
            status_code = parts[-2]  # Second to last part is status code
            if status_code in status_codes:
                status_codes[status_code] += 1
            if logs % 10 == 0:
                print_statistics(status_codes, total_size)
        except (ValueError, KeyError, IndexError) as e:
            print(f"Skipping line due to error: {e}", file=sys.stderr)
finally:
    print_statistics(status_codes, total_size)
