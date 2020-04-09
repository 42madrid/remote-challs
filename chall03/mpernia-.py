#!/usr/bin/env python3

import sys

def ending_def(col_start, col_end, row_end, row_start):
	if col_start >= col_end and row_start >= row_end: return ""
	else: return ", "

def print_hline(matrix, n, start, end, x, ending):
	print(", ".join(matrix[n][i] for i in range(start, end, x)), end = ending)

def print_vline(matrix, n, start, end, x, ending):
	print(", ".join(matrix[i][n] for i in range(start, end, x)), end = ending)

def print_snail(matrix, arg_len):
	row_start = col_start = 0
	row_end = col_end = arg_len - 1
	while row_start <= row_end and col_start <= col_end:
		ending = ending_def(col_start, col_end, row_end, row_start)
		print_hline(matrix, row_start, col_start, col_end + 1, 1, ending)
		row_start += 1
		ending = ending_def(col_start, col_end, row_end, row_start)
		print_vline(matrix, col_end, row_start, row_end +1, 1, ending)
		col_end -= 1
		if row_start <= row_end:
			ending = ending_def(col_start, col_end, row_end, row_start)
			print_hline(matrix, row_end, col_end, col_start - 1, -1, ending)
		row_end -= 1
		if col_start <= col_end:
			ending = ending_def(col_start, col_end, row_end, row_start)
			print_vline(matrix, col_start, row_end, row_start - 1, -1, ending)
		col_start += 1
	print()

def error():
	print("usage: ", sys.argv[0], "<1-9 squared_rows>")
	exit()

arg_len = len(sys.argv) - 1
if arg_len in range(1, 21) and all(len(sys.argv[i]) == arg_len and sys.argv[i].isnumeric() for i in (1, arg_len)):
	matrix = []
	matrix_range = range(0, arg_len)
	for i in matrix_range:
		matrix.append([])
		for j in matrix_range:
			if sys.argv[i + 1][j] == '0': error()
			matrix[i].append(sys.argv[i + 1][j])
	print_snail(matrix, arg_len)
else: error()
