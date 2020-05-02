#!/usr/bin/env python3

_VALID_ACTIONS = "IKNSWE"
_INNER_GRID = "M0*"
_OUTER_GRID = "+E"
_WALL = "+"
_MINE = "*"
_ROBOT = "M"
_EXIT = "E"
_INIT = "I"
_STOP = "K"

def get_minefield():
    minefield = []
    err = False

    try:
        line = input()
        while line:
            minefield.append(line)
            line = input()
    except EOFError:
        err = True
        return minefield, err
    return minefield, err

def get_actions():
    err = False
    actions = ""

    try:
        actions = input()
    except EOFError:
        err = True
        return actions, err
    return actions, err

def equal_width(minefield):
    length = len(minefield[0])

    for row in minefield:
        if len(row) != length: 
            break
    return len(row) == length

def exit_in_corner(minefield):
    height_idx = len(minefield) - 1
    width_idx = len(minefield[0]) - 1

    if minefield[0][0] == _EXIT or \
       minefield[0][width_idx] == _EXIT or \
       minefield[height_idx][0] == _EXIT or \
       minefield[height_idx][width_idx] == _EXIT:
        return True
    return False

def one_exit(minefield):
    exits = minefield[0].count(_EXIT)
    exits += minefield[-1].count(_EXIT)
    
    for row in minefield[1:-1]:
        if exits > 1:
            break
        if row[0] in _EXIT or row[-1] in _EXIT:
            exits += 1
    return exits == 1

def check_outer_grid(minefield):
    if exit_in_corner(minefield) or \
       not all(c in _OUTER_GRID for c in minefield[0][1:-1]) or \
       not all(c in _OUTER_GRID for c in minefield[-1][1:-1]) or \
       not all(row[0] in _OUTER_GRID and row[-1] in _OUTER_GRID for row in minefield[1:-1]) or \
       not one_exit(minefield):
        return False
    return True

def check_inner_grid(minefield):
    robots = 0

    for row in minefield[1:-1]:
        robots += row[1:-1].count(_ROBOT)
        if not all(c in _INNER_GRID for c in row[1:-1]):
            return False
    return robots == 1

def validate_minefield(minefield):
    if not minefield or len(minefield) < 3 or \
       len(minefield[0]) < 3 or not equal_width(minefield) or \
       not check_outer_grid(minefield) or not check_inner_grid(minefield):
        return False
    return True

def validate_actions(actions):
    if not actions or not all(c in _VALID_ACTIONS for c in actions):
        return False
    return True

def robot_position(minefield):
    for x, row in enumerate(minefield):
        for y, col in enumerate(row):
            if col in _ROBOT:
                return x, y
    return -1, -1

def move_robot_exit(minefield, action, row, col):
    height_idx = len(minefield) - 1
    width_idx = len(minefield[0]) - 1

    if action in "N" and row > 0 and col in range(1, width_idx):
        row -= 1
    elif action in "S" and row < height_idx and col in range(1, width_idx):
        row += 1
    elif action in "W" and col > 0 and row in range(1, height_idx):
        col -= 1
    elif action in "E" and col < width_idx and  row in range(1, height_idx):
        col += 1
    return row, col

def move_robot(minefield, action, row, col):
    if action in "N" and minefield[row - 1][col] not in _WALL:
        row -= 1
    elif action in "S" and minefield[row + 1][col] not in _WALL:
        row += 1
    elif action in "W" and minefield[row][col - 1] not in _WALL:
        col -= 1
    elif action in "E" and minefield[row][col + 1] not in _WALL:
        col += 1
    return row, col

def remote_control(minefield, actions):
    on = False

    row, col = robot_position(minefield)
    if row == -1 or col == -1:
        return
    for action in actions:
        if minefield[row][col] in _MINE:
            break
        if action in _INIT and on == False:
            on = True
        elif action in _STOP and on == True:
            on = False
        elif on == True and minefield[row][col] in _EXIT:
            row, col = move_robot_exit(minefield, action, row, col)
        elif on == True:
            row, col = move_robot(minefield, action, row, col)

    if minefield[row][col] in _MINE:
        print("Exploded.")
    elif minefield[row][col] in _EXIT and on == False:
        print("Success.")
    else:
        print("Failure.")

def main():
    try:
        while True:
            minefield, err = get_minefield()
            if err:
                return
            actions, err = get_actions()
            if err:
                return
            if not validate_minefield(minefield) or not validate_actions(actions):
                print("{}: Invalid input.".format(__file__))
                continue
            remote_control(minefield, actions)
    except KeyboardInterrupt:
        print()
        return

if __name__ == "__main__":
    main()
