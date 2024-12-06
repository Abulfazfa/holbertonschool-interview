import sys

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
    for line in sys.stdin:
        try:
            logs += 1
            new_line = line.rstrip().split(" ")
            if len(new_line) < 2:
                continue  # Skip malformed lines
            total_size += int(new_line[-1])
            status_code = new_line[-2]
            if status_code in status_codes:
                status_codes[status_code] += 1
            if logs % 10 == 0:
                print_statistics(status_codes, total_size)
        except (ValueError, IndexError) as e:
            print(f"Error processing line: {line}, Error: {e}", file=sys.stderr)
finally:
    print_statistics(status_codes, total_size)
