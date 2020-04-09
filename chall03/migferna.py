#!/usr/bin/env python3

import sys

def snail(matrix):
    res = []
    if len(matrix) == 0:
        return res
    row_begin = 0
    row_end = len(matrix) - 1
    col_begin = 0
    col_end = len(matrix[0]) - 1

    while row_begin <= row_end and col_begin <= col_end:
        for i in range(col_begin, col_end + 1):
            res.append(matrix[row_begin][i])
        row_begin += 1

        for i in range(row_begin, row_end+1):
            res.append(matrix[i][col_end])
        col_end -= 1

        if row_begin <= row_end:
            for i in range(col_end, col_begin - 1, -1):
                res.append(matrix[row_end][i])
        row_end -= 1

        if (col_begin <= col_end):
            for i in range(row_end, row_begin - 1, -1):
                res.append(matrix[i][col_begin])
        col_begin += 1
    return res

def get_arg():
    matrix = []
    if len(sys.argv) < 2 or (len(sys.argv) - 1 != len(sys.argv[1])):
        return None
    for i in sys.argv[1:]:
        matrix.append(list(i))
    return matrix

def usage():
    return print("usage: ./%s.py <1-9 squared_rows...>" % sys.argv[1])

def main():
    arg = get_arg()
    if arg is None:
        return usage()
    print(snail(arg))

if __name__ == "__main__":
    main()
