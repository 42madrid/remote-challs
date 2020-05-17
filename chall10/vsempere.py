#! /usr/local/bin/python3

import sys
import re

def check_east(i, map):
    if (i < 0 or i >= 42 or (i % 7) > 3):
        return 0
    if (map[i] == 1 and (map[i:i + 4] == [1,1,1,1])):
        return 1
    elif (map[i] == 2 and (map[i:i + 4] == [2,2,2,2])):
        return 2
    return 0


def check_west(i, map):
    if (i < 0 or i >= 42 or (i % 7) < 3):
        return 0
    if (map[i] == 1 and (map[i-4:i] == [1,1,1,1])):
        return 1
    elif (map[i] == 2 and (map[i-4:i] == [2,2,2,2])):
        return 2
    return 0


def check_north(i, map):
    if (i < 0 or i >= 14):
        return 0
    if (map[i] > 0 and map[i + 7] == map[i] and map[i + 14] == map[i] 
    and map[i + 21] == map[i]):
        return map[i]
    return 0

def check_north_west(i, map):
    if (i < 0 or i >= 14 or (i % 7) < 3):
        return 0
    if (map[i] > 0 and map[i + 6] == map[i] and map[i + 12] == map[i] 
    and map[i + 18] == map[i]):
        return map[i]
    return 0

def check_north_east(i, map):
    if (i < 0 or i >= 14 or (i % 7) >= 2):
        return 0
    if (map[i] > 0 and map[i + 8] == map[i] and map[i + 16] == map[i] 
    and map[i + 24] == map[i]):
        return map[i]
    return 0

def matches_win_condition_horizontal(map, row, col):
    matches = 1
    pos = row * 7 + col
    toMatch = map[pos]
    offset = 1
    while ((col + offset) < 7 and map[pos + offset]==toMatch and matches < 4):
        matches = matches + 1 
        offset = offset + 1
    offset = 1
    while ((col - offset) > -1 and map[pos - offset]==toMatch and matches < 4):
        matches = matches + 1
        offset = offset + 1
    if (matches >= 4):
        return 1
    else:
        return 0

def matches_win_condition_vertical(map, row, col):
    matches = 1
    pos = row * 7 + col
    toMatch = map[pos]
    offset = 7
    while ((pos + offset) < 42 and map[pos + offset]==toMatch and matches < 4):
        matches = matches + 1 
        offset = offset + 7
    offset = 7
    while ((pos - offset) > -1 and map[pos - offset]==toMatch and matches < 4):
        matches = matches + 1
        offset = offset + 7
    if (matches >= 4):
        return 1
    else:
        return 0

def matches_win_condition_diagonal_sw_ne(map, row, col):
    realRow = row + 1
    matches = 1
    pos = row * 7 + col
    toMatch = map[pos]
    offset = 8
    while (realRow < 6 and (col + (realRow - row)) < 7 and 
    (pos + offset) < 42 and 
    map[pos + offset]==toMatch and matches < 4):
        matches = matches + 1
        offset = offset + 8
        realRow = realRow + 1
    offset = 6
    realRow = row - 1
    while (realRow > -1 and (pos - offset) > -1 and
    (col - (row - realRow)) > -1 and
    map[pos - offset]==toMatch and matches < 4):
        matches = matches + 1
        offset = offset - 6
        realRow = realRow - 1
    if (matches >= 4):
        return 1
    else:
        return 0


def matches_win_condition_diagonal_nw_se(map, row, col):
    realRow = row + 1
    matches = 1
    pos = row * 7 + col
    toMatch = map[pos]
    offset = 6
    while (realRow < 6 and (pos + offset) < 42 and
    (col + (realRow - row)) < 7 and 
    map[pos + offset]==toMatch and matches < 4):
        matches = matches + 1
        offset = offset - 6
        realRow = realRow + 1
    offset = 8
    realRow = row - 1
    while (realRow > -1 and (pos - offset) > -1 and
    (col - (row - realRow)) > -1 and
    map[pos - offset]==toMatch and matches < 4):
        matches = matches + 1
        offset = offset - 6
        realRow = realRow - 1
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