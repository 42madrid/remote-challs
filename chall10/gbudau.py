#!/usr/bin/env python3

import fileinput
import sys
import curses.ascii

POSITION = "ABCDEFG"
TEAMS = [1, 2]
NOT_CONNECTED = 3
CONNECTED = 4
ROWS = 6
COLUMNS = 7

def init_board():
    board = [[0] * COLUMNS for i in range(COLUMNS)]
    return(board)

def valid_input(action):
    if not action or len(action) < 3 or action[0] not in POSITION or \
       action[1] not in "_" or not curses.ascii.isupper(action[2]):
        return False
    return True

def check_horizontal(board, team, row, col):
    connect = 0
    for i in board[row][col:]:
        if i == TEAMS[team]:
            connect += 1
        else:
            break
    for i in board[row][:col][::-1]:
        if i == TEAMS[team]:
            connect += 1
        else:
            break
    return team if connect >= CONNECTED else NOT_CONNECTED

def check_vertical(board, team, row, col):
    connect = 0
    for i in range(1, row)[::-1]:
        if board[i][col] == TEAMS[team]:
            connect += 1
        else:
            break
    for i in range(row, ROWS + 1):
        if board[i][col] == TEAMS[team]:
            connect += 1
        else:
            break
    return team if connect >= CONNECTED else NOT_CONNECTED

def check_diagonal_nesw(board, team, row, col):
    connect = 0
    j = col
    for i in range(1, row)[::-1]:
        j += 1
        if j < COLUMNS and board[i][j] == TEAMS[team]:
            connect += 1
        else:
            break
    j = col
    for i in range(row, ROWS + 1):
        if j >= 0 and board[i][j] == TEAMS[team]:
            connect += 1
            j -= 1
        else:
            break
    return team if connect >= CONNECTED else NOT_CONNECTED

def check_diagonal_nwse(board, team, row, col):
    connect = 0
    j = col
    for i in range(1, row)[::-1]:
        j -= 1
        if j >= 0 and board[i][j] == TEAMS[team]:
            connect += 1
        else:
            break
    j = col
    for i in range(row, ROWS + 1):
        if j < COLUMNS and board[i][j] == TEAMS[team]:
            connect += 1
            j += 1
        else:
            break
    return team if connect >= CONNECTED else NOT_CONNECTED

def check_diagonals(board, team, row, col):
    connected = check_diagonal_nesw(board, team, row, col)
    if connected != NOT_CONNECTED:
        return team
    connected = check_diagonal_nwse(board, team, row, col)
    if connected != NOT_CONNECTED:
        return team
    return NOT_CONNECTED

def check_connections(board, team, row, col):
    connected = check_horizontal(board, team, row, col)
    if connected != NOT_CONNECTED:
        return board, team
    connected = check_vertical(board, team, row, col)
    if connected != NOT_CONNECTED:
        return board, team
    connected = check_diagonals(board, team, row, col)
    if connected != NOT_CONNECTED:
        return board, team
    return board, NOT_CONNECTED

def connect_four(board, team, position):
    for i, row in enumerate(board[:ROWS - 1], 1):
        if board[i + 1][position]:
            board[i][position] = TEAMS[team]
            return check_connections(board, team, i, position)
    board[i + 1][position] = TEAMS[team]
    return check_connections(board, team, i + 1, position)

def main():
    board = init_board()
    teams = []
    for turn, line in enumerate(fileinput.input()):
        action = line.rstrip("\n")
        if not valid_input(action):
            sys.exit("Invalid input.")
        if not turn:
            teams.append(action[2:])
        elif turn == 1 and teams[0] != action[2:]:
            teams.append(action[2:])
        elif teams[prev] == action[2:]:
                sys.exit("Invalid input.")
        prev = turn % 2
        idx = POSITION.index(action[0])
        board[0][idx] += 1
        if not board[0][idx] <= ROWS:
            sys.exit("Invalid input.")
        board, connected = connect_four(board, turn % 2, idx)
        if connected != NOT_CONNECTED:
            sys.exit("{}.".format(teams[connected]))
    print("Draw.")

if  __name__ == "__main__":
    main()
