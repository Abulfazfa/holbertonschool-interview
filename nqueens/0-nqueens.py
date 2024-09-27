#!/usr/bin/python3
"""N Queens puzzle solution
"""

import sys

def solve_nqueens(N):
    "function solve nqueens"
    solutions = []
    current_solution = [-1] * N  # Initialize empty board, where current_solution[row] = column

    def is_safe(row, col):
        for prev_row in range(row):
            prev_col = current_solution[prev_row]
            if (prev_col == col or                  # Same column
                prev_row - prev_col == row - col or  # Same / diagonal
                prev_row + prev_col == row + col):  # Same \ diagonal
                return False
        return True

    def backtrack(row):
        "function backtrack it accept row"
        if row == N:
            solutions.append([(r, current_solution[r]) for r in range(N)])
            return
        for col in range(N):
            if is_safe(row, col):
                current_solution[row] = col
                backtrack(row + 1)
                current_solution[row] = -1

    backtrack(0)
    return solutions

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
        if N < 4:
            print("N must be at least 4")
            sys.exit(1)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    solutions = solve_nqueens(N)
    for solution in solutions:
        print(solution)
