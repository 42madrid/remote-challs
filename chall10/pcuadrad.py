#!/usr/bin/env python3
import sys

lettersValid = "ABCDEFG"

def checker(lstInput: list) -> bool:
    '''Check the input user That the box is between A-G,
        that the second parameter after '_' is capitalized and 
        there are only two and they alternate '''

    if len(lstInput) > 42:
        return False
    for elem, i in zip(lstInput, range(len(lstInput))):
        if str(elem).find('_') == -1:
            return False
        newcolor = str(elem).split('_')
        if newcolor[0] not in lettersValid or not newcolor[1].istitle():
            return False
        if i % 2 == 0:
            if i > 0 and (fcolor[1] != newcolor[1] or newcolor[1] == scolor[1]):
                return False
            fcolor = newcolor
        else:
            if i > 1 and (scolor[1] != newcolor[1] or newcolor[1] == fcolor[1]):
                return False
            scolor = newcolor
    return True

def retRow(table: list, col: int) -> int:
    '''Function that returns the row to be filled in the given column'''

    for row, n_row in zip(reversed(table), range(len(table) - 1, -1, -1)):
        if row[col] == '0':
            return n_row
    return -1

def check_full(table: list, row: int, col: int, c_row: int, c_col: int, turn: chr) -> bool:
    '''Check in the table if there are 4 matches in a row.'''

    count = 1
    while row < 5 and col < 6 and col > 0:
        if table[row][col] == turn and table[row][col] == table[row - c_row][col - c_col]:
            count += 1
        else:
            count = 1
        if count == 4:
            return True
        col -= c_col
        row -= c_row
    return False

def check_win(table: list, row: int, col: int, turn: chr) -> bool:
    '''Calls check_full with the aproppiate parametters to check the row, column line and the diagonal.
        table -> table of the game.\n
        row -> index of the row of last movement.\n
        col -> index of the column of last movement'''

    #check row
    if check_full(table, row, col, 0, -1, turn) or check_full(table, row, col, 0, 1, turn):
        return True
    #check column
    if check_full(table, row, col, -1, 0, turn):
        return True
    #check diagonal
    if check_full(table, row, col, -1, -1, turn) or check_full(table, row, col, -1, 1, turn):
        return True
    return False

def game(lstInput: list, table: list) -> bool:
    '''Function that fills the board according to the instructions that the user has entered.\n
        lstInput -> list of the moves.
        table -> table of the game 6*7.'''

    players = {'1': str(lstInput[0]).split('_')[1], '2': str(lstInput[1]).split('_')[1]}
    for elem, n in zip(lstInput, range(len(lstInput))):
        turnMove = '1' if not n % 2 else '2'
        move = str(elem).split('_')
        col = lettersValid.find(move[0])
        row = retRow(table, col)
        if row == -1:
            continue
        table[row][col] = turnMove
        if check_win(table, row, col, turnMove):
            print(players.get(turnMove)+'.')
            return True
    return False

def main():
    '''Save the input and remove '\\n' from the end.\n
        @inputlst -> list containing user input.\n
        @table -> board where the boxes will be filled in each turn.'''

    inputlst = []
    for line in sys.stdin:
        line = line.rstrip('\n')
        if len(line) > 0:
            inputlst.append(line)
    if not checker(inputlst):
        print("Invalid input.")
    else:
        table = []
        for _ in range(6):
            table.append(['0'] * 7)
        if len(inputlst) < 3 or not game(inputlst, table):
            print("Draw.")

if __name__ == "__main__":
    main()