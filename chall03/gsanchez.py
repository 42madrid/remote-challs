#!/usr/bin/env python3

import sys

def get_args():
    n_args = len(sys.argv) - 1
    if n_args is 0:
        return None
    for rows in sys.argv[1:]:
        n_rows = len(rows)
        if n_rows is not n_args or not rows.isnumeric():
            return None
    return sys.argv[1:]

def snail_sort(matrix):
    snailed = []
    row_begin = 0
    row_end = len(matrix) - 1
    col_begin = 0
    col_end = len(matrix[0]) - 1

    while row_begin <= row_end and col_begin <= col_end:
        for i in range(col_begin, col_end + 1):
            snailed.append(matrix[row_begin][i])
        row_begin += 1

        for i in range(row_begin, row_end + 1):
            snailed.append(matrix[i][col_end])
        col_end -= 1

        if row_begin <= row_end:
            for i in range(col_end, col_begin - 1, -1):
                snailed.append(matrix[row_end][i])
        row_end -= 1

        if col_begin <= col_end:
            for i in range(row_end, row_begin - 1, -1):
                snailed.append(matrix[i][col_begin])
            col_begin += 1
    print (*snailed, sep = ", ")

def main():
    matrix = get_args()
    if matrix is None:
        return print("usage: %s <1-9 squared_rows...>" % sys.argv[0])
    snail_sort(matrix)

if __name__ == "__main__":
    main()
