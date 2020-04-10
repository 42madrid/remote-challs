#!/usr/bin/env python3
import sys

def printUsage():
    print('usage: ./vsempere.py <1-9 squared_rows...>');

def getOffset(direction, board_size):
    if direction == 0:
        return 1;
    if direction == 1:
        return board_size;
    if direction == 2:
        return -1;
    return -board_size;

def buildArray(argv):
    if (len(argv)<=1 or len(argv)>=10):
        return None;

    board = [];
    i = 1;
    row_len = len(argv[i]);
    while (i <len(argv)):
        if (row_len != len(argv[i])):
            return None;
        for e in argv[i]:
            if not e.isnumeric():
                return None;
        board[len(board):] = [argv[i]];
        i+=1;
    return board;

def getLinearBoard(data):
    board = [];
    for row in data:
        for e in row:
            board[len(board):] = [e];
    return board;

def nextDirection(direction):
    new_dir = (direction + 1) % 4;
    return new_dir;

def checkBoard(board):
    if board is None or len(board)<1 or len(board)>9:
        return 0;
    row_len = len(board[0]);
    rows = 0;
    for row in board:
        if (row_len != len(row)):
            return 0;
        for cell in row:
            if (not cell.isnumeric()):
                return 0;
        rows+=1;
    if (rows==row_len):
       return 1; 
    return 0;

def snail(board):
    if checkBoard(board) <= 0:
        printUsage();
        return (-1);
    direction = 0;
    board_linear = getLinearBoard(board);
    board_side = len(board[0]);
    row_size = board_side;
    offset = getOffset(direction, board_side);
    pos = 0;
    printed_chars = 0;
    printed_chars_in_row = 0;
    while printed_chars < (board_side * board_side):
        if (printed_chars > 0):
            print(', ', end='');
        print(board_linear[pos], end='');
        printed_chars_in_row += 1;
        printed_chars += 1;
        if printed_chars_in_row==row_size:
            printed_chars_in_row=0;
            direction = nextDirection(direction);
            offset = getOffset(direction, board_side);
            if direction == 1 or direction == 3:
                row_size-=1;    
        pos+=offset;

def main(argv):
    board = buildArray(argv);
    snail(board);

if __name__ == '__main__':
	main(sys.argv);
