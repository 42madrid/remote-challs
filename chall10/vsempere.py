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

def check_winner(map):
    i = 0
    while (i < 42):
        if (check_east(i, map) or check_west(i, map) or 
        check_north(i, map) or check_north_west(i, map) or 
        check_north_east(i, map)):
            return map[i]
        i = i + 1

    return 0
    
def process_user_input(user_input):
    if (not isinstance(user_input, list)):
        return None, None;

    plyrs = [None, None]
    cols = [0, 0, 0, 0, 0, 0, 0]
    turn = 0
    map = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    xpr_reg = re.compile(r"(\S+)_(\S+)")
    for line in user_input:
        matches = xpr_reg.match(line)
        if (matches is None):
            continue
        col = matches.group(1)
        colour = matches.group(2)
        colIndex = ord(col) - ord('A')
        if (colIndex < 0 or colIndex > 6):
            return None, None

        rowInCol = cols[colIndex]
        if (rowInCol >= 6):
            return None, None
        
        if (map[(rowInCol * 7) + colIndex] > 0):
            return None, None
        
        map[(rowInCol * 7) + colIndex] = (turn + 1)
        cols[colIndex] = cols[colIndex] + 1

        if (turn == 0 and plyrs[0] is None):
            plyrs[0] = colour
        elif (turn == 1 and plyrs[1] is None):
            plyrs[1] = colour
        
        if (turn == 0 and plyrs[0] != colour):
            return None, None
        elif (turn == 1 and plyrs[1] != colour):
            return None, None
        turn = (turn + 1) % 2
    return map, plyrs

def main():
    user_input = sys.stdin.readlines()

    map, plyrs = process_user_input(user_input)
    if (map is None):
        print("Invalid input.")
    else:
        winner = check_winner(map)
        if (winner > 0):
            print(plyrs[winner - 1] + '.')
        else:
            print("Draw.")
    sys.exit(0)

if __name__ == "__main__":
	main()