#! /usr/local/bin/python3

import sys
import re

def cell_matches_value(map, valueToMatch, row, col):
    if (row < 0 or row > 5 or col < 0 or col > 6):
        return -1
    elif (map[(row * 7) + col] == valueToMatch):
        return map[(row * 7) + col]
    else:
        return 0

def matches_win_condition_horizontal(map, row, col):
    matches = 1
    value_to_match = map[(row * 7) + col]
    i = col + 1
    while (cell_matches_value(map, value_to_match, row, i) > 0 and 
    matches < 4):
        i = i + 1
        matches = matches + 1
    i = col - 1
    while (cell_matches_value(map, value_to_match, row, i) > 0 and 
    matches < 4):
        i = i - 1
        matches = matches + 1
    if (matches >= 4):
        return 1
    else:
        return 0

def matches_win_condition_vertical(map, row, col):
    matches = 1
    value_to_match = map[(row * 7) + col]
    i = row + 1
    while (cell_matches_value(map, value_to_match, i, col) > 0 and 
    matches < 4):
        i = i + 1
        matches = matches + 1
    i = row - 1
    while (cell_matches_value(map, value_to_match, i, col) > 0 and 
    matches < 4):
        i = i - 1
        matches = matches + 1
    if (matches >= 4):
        return 1
    else:
        return 0

def matches_win_condition_diagonal_sw_ne(map, row, col):
    matches = 1
    value_to_match = map[(row * 7) + col]
    i = row + 1
    j = col + 1
    while (cell_matches_value(map, value_to_match, i, j) > 0 and 
    matches < 4):
        i = i + 1
        j = j + 1
        matches = matches + 1
    i = row - 1
    j = col - 1
    while (cell_matches_value(map, value_to_match, i, j) > 0 and 
    matches < 4):
        i = i - 1
        j = j - 1
        matches = matches + 1
    if (matches >= 4):
        return 1
    else:
        return 0

def matches_win_condition_diagonal_nw_se(map, row, col):
    matches = 1
    value_to_match = map[(row * 7) + col]
    i = row + 1
    j = col - 1
    while (cell_matches_value(map, value_to_match, i, j) > 0 and 
    matches < 4):
        i = i + 1
        j = j - 1
        matches = matches + 1
    i = row - 1
    j = col + 1
    while (cell_matches_value(map, value_to_match, i, j) > 0 and 
    matches < 4):
        i = i - 1
        j = j + 1
        matches = matches + 1
    if (matches >= 4):
        return 1
    else:
        return 0


def check_winner(map, row, col):
    i = 0
    if (matches_win_condition_horizontal(map, row, col) or
        matches_win_condition_vertical(map, row, col) or
        matches_win_condition_diagonal_sw_ne(map, row, col) or
        matches_win_condition_diagonal_nw_se(map, row, col)):
        return map[(row * 7) + col]
    return 0
    
def process_user_input(user_input):
    if (not isinstance(user_input, list) or len(user_input) > 42):
        return None;

    plyrs = [None, None]
    cols = [0, 0, 0, 0, 0, 0, 0]
    turn = 0
    map = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    xpr_reg = re.compile(r"(\S+)_(\S+)")
    movs = 0
    for line in user_input:
        matches = xpr_reg.match(line)
        if (matches is None):
            continue
        col = matches.group(1)
        colour = matches.group(2)
        colIndex = ord(col) - ord('A')
        if (colIndex < 0 or colIndex > 6):
            return None

        rowInCol = cols[colIndex]
        if (rowInCol >= 6):
            return None
        
        if (map[(rowInCol * 7) + colIndex] > 0):
            return None
        
        map[(rowInCol * 7) + colIndex] = (turn + 1)
        cols[colIndex] = cols[colIndex] + 1

        if (turn == 0 and plyrs[0] is None):
            plyrs[0] = colour
        elif (turn == 1 and plyrs[1] is None):
            plyrs[1] = colour

        if (movs >= 6):
            winner = check_winner(map, rowInCol, colIndex)
            if (winner > 0):
                return plyrs[winner - 1]

        if (turn == 0 and plyrs[0] != colour):
            return None
        elif (turn == 1 and plyrs[1] != colour):
            return None
        turn = (turn + 1) % 2
        movs = movs + 1
    return "Draw"

def main():
    user_input = sys.stdin.readlines()

    winner = process_user_input(user_input)
    if (winner is None):
        print("Invalid input.")
    else:
        print(winner + ".")
    sys.exit(0)

if __name__ == "__main__":
	main()