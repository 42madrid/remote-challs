#! /usr/local/bin/python3

import sys

def process_user_input(user_input):
    if (not isinstance(user_input, list)):
        return None, None, None, 'Invalid input.';

    map_line_size = -1
    map_read = 0
    moves_read = 0
    map = ""
    for line in user_input:
        line = line.rstrip()
        if (map_read == 0):
            if (len(line) == 0):
                map_read = 1
            else:
                if (map_line_size < 0):
                    map_line_size = len(line)
                elif (map_line_size != len(line)):
                    return None, None, None, 'Invalid input.'
                map = map + line
        else:
            if (moves_read == 0):
                moves = line
                moves_read = 1
            else:
                return None, None, None, 'Invalid input.'
    return map, map_line_size, moves, None

def check_user_input(map, map_line_size, moves):
    if (map is None or map_line_size is None or moves is None):
        return 0

    rows = len(map) / map_line_size
    row = 0
    col = 0
    exits = 0
    robots = 0
    for map_cell in map:
        if (row == 0  or row == (rows-1) or col == 0 or col == (map_line_size -1)):
            if (not map_cell in "+E"):
                return 0
            if (map_cell == "E"):
                exits = exits + 1
        else:
            if (not map_cell in "0*M"):
                return 0
            if (map_cell == 'M'):
                robots = robots + 1
        col = col + 1
        if (col == map_line_size):
            col = 0
            row = row + 1
    
    if (row != rows or robots != 1 or exits != 1):
        return 0
    
    for move in moves:
        if (not move in "IKNSEW"):
            return 0
    return 1

def get_robot_pos(map):
    pos = 0
    for cell in map:
        if cell=='M':
            return pos
        pos = pos + 1

def move_robot(move, rpos, map_line_size):
    if move == "N":
        return rpos - map_line_size
    if move == "S":
        return rpos + map_line_size
    if (move == 'E'):
        return rpos + 1
    if (move == 'W'):
        return rpos - 1
    return rpos

def valid_move(map, rpos):
    if map[rpos] in "0*EM":
        return 1
    return 0

def apply_moves(map, map_line_size, moves):
    rpos = get_robot_pos(map)

    engine_started = 0
    for move in moves:
        if not engine_started:
            if (move == 'I'):
                engine_started = 1
        else:
            if (move == 'K'):
                engine_started = 0
            else: 
                new_rpos = move_robot(move, rpos, map_line_size)
                if (valid_move(map, new_rpos)):
                    rpos = new_rpos
                    if (map[rpos] == '*'):
                        return ('Exploded.', 2)
    if (map[rpos] == 'E' and engine_started == 0):
        return ('Success.', 0)
    return ('Failure.', 1)

def main():
    user_input = sys.stdin.readlines()

    map, map_line_size, moves, error = process_user_input(user_input)
    if not error is None:
        print(error)
        sys.exit(1)
    if check_user_input(map, map_line_size, moves) == 0:
        print("Invalid input.")
        sys.exit(1)
    result, result_code = apply_moves(map, map_line_size, moves)
    print(result)
    sys.exit(result_code)

if __name__ == "__main__":
	main()