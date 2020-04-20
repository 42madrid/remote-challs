# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cdorta-n.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdorta-n <cdorta-n@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/09 14:55:59 by cdorta-n          #+#    #+#              #
#    Updated: 2020/04/09 14:55:59 by cdorta-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def error():
	sys.stderr.write("usage: ./cdorta-n.py <1-9 squared_rows ...>\n")
	exit(1)

def spiral_traversal(matrix):
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
		for i in range(row_begin, row_end + 1):
			res.append(matrix[i][col_end])
		col_end -= 1

		if row_begin <= row_end:
			for i in range(col_end, col_begin-1, -1):
				res.append(matrix[row_end][i])
		row_end -= 1

		if col_begin <= col_end:
			for i in range(row_end, row_begin - 1, -1):
				res.append(matrix[i][col_begin])
		col_begin += 1	
	return res

def main():
	if not len(sys.argv) >= 2 and len(sys.argv) <= 21:
		error()
	else:
		c = 1
		y = len(sys.argv) - 1
		x = len(sys.argv[1])
		matrix = [[0 for a in range(x)] for b in range(y)]
		if x != y:
			error()
		while c <= y:
			if len(sys.argv[c]) != x:
				error()
			c += 1
		c = 1
		c2 = 0
		while c <= y:
			while c2 < x:
				if not sys.argv[c][c2].isdigit():
					error()
				matrix[c - 1][c2] = sys.argv[c][c2]
				c2 += 1
			c += 1
			c2 = 0
		print(*spiral_traversal(matrix), sep = ", ")
if __name__ == "__main__":
	main()