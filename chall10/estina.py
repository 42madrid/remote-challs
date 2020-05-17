#!/usr/bin/env python3

import sys

ROWS = 6
COLS = 7

def check_line(line, colors, split_line):
	if len(split_line[0]) != 1:
		exit("Invalid input.")
	if not len(colors) or (len(colors) != 2 and colors[0] != split_line[1]):
		colors.append(split_line[1])
	elif colors[0] != split_line[1] and colors[1] != split_line[1]:
		exit("Invalid input.")
	index = ord(split_line[0]) - ord('A')
	if index < 0 or index > 6 or len(split_line) != 2:
		exit("Invalid input.")
	return index

def winning_move(board, piece):
	# Check horizontal locations for win
	for c in range(COLS - 3):
		for r in range(ROWS):
			if board[r + c * ROWS] == piece \
			and board[r + (c + 1) * ROWS] == piece \
			and board[r + (c + 2) * ROWS] == piece \
			and board[r + (c + 3) * ROWS] == piece:
				return True

	# Check vertical locations for win
	for c in range(COLS):
		for r in range(ROWS - 3):
			if board[r + c * ROWS] == piece \
			and board[(r + 1) + c * ROWS] == piece \
			and board[(r + 2) + c * ROWS] == piece \
			and board[(r + 3) + c * ROWS] == piece:
				return True

	# Check positively sloped diaganols
	for c in range(COLS - 3):
		for r in range(ROWS - 3):
			if board[r + c * ROWS] == piece \
			and board[(r + 1) + (c + 1) * ROWS] == piece \
			and board[(r + 2) + (c + 2) * ROWS] == piece \
			and board[(r + 3) + (c + 3) * ROWS] == piece:
				return True

	# Check negatively sloped diaganols
	for c in range(COLS - 3):
		for r in range(3, ROWS):
			if board[r + c * ROWS] == piece \
			and board[(r - 1) + (c + 1) * ROWS] == piece \
			and board[(r - 2) + (c + 2) * ROWS] == piece \
			and board[(r - 3) + (c + 3) * ROWS] == piece:
				return True


def check_winner(board, colors):
	for color in colors:
		if winning_move(board, color):
			return color + "."
	return "Draw."

def main():
	lines = []
	for line in sys.stdin:
		lines.append(line.rstrip("\n"))
	lines_len = len(lines)
	if not lines_len:
		exit("Draw.")
	elif lines_len > 42:
		exit("Invalid input.")
	board = [" "] * 42
	colors = []
	for line in lines:
		split_line = line.split("_")
		index = check_line(line, colors, split_line)
		for i in range(COLS):
			if board[index + i * COLS] == " ":
				board[index + i * COLS] = split_line[1]
				break
	for cell in board:
		if not board:
			board = " "
	print(check_winner(board, colors))

if __name__ == "__main__":
	main()
