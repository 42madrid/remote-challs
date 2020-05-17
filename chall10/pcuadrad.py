#!/usr/bin/env python3
import sys

lettersValid = "ABCDEFG"

def checker(lstInput: list) -> bool:
    if len(lstInput) > 42:
        return False
    for elem, i in zip(lstInput, range(len(lstInput))):
        if str(elem).find('_') == -1:
            return False
        newcolor = str(elem).split('_')
        if newcolor[0] not in lettersValid:
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
    for row, n_row in zip(reversed(table), range(len(table) - 1, 0, -1)):
        if row[col] == '0':
            return n_row
    return -1

def check_win(table: list) -> bool:
    #check row
    for n_row in range(len(table) - 1, 0, -1):
        count = 1
        for col in range(len(table[n_row])):
            if col > 0 and table[n_row][col] != '0':
                if table[n_row][col] == table[n_row][col - 1]:
                    count += 1
                else:
                    count = 1
            if count == 4:
                return True
    #check column
    for n_col in range(7):
        count = 1
        for n_row in range(len(table)):
            if n_row > 0 and table[n_row][n_col] != '0':
                if table[n_row][n_col] == table[n_row - 1][n_col]:
                    count += 1
                else:
                    count = 1
            if count == 4:
                return True
    #check diagonal
    
    return False

def game(lstInput: list, table: list) -> bool:
    players = {'1': str(lstInput[0]).split('_')[1], '2': str(lstInput[1]).split('_')[1]}
    for elem, n in zip(lstInput, range(len(lstInput))):
        turnMove = '1' if not n % 2 else '2'
        move = str(elem).split('_')
        col = lettersValid.find(move[0])
        row = retRow(table, col)
        if row == -1:
            continue
        table[row][col] = turnMove
        if check_win(table):
            print(players.get(turnMove)+'.')
            return True
    return False

def main():
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