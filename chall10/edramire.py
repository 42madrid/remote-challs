#! /usr/bin/env python3

import sys
import re
from enum import Enum


class Cell(Enum):
    EMPTY = '.'
    RED = 'O'
    BLUE = 'X'

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        return self.__str__()


class Connect:
    def __init__(self):
        self.grid = [[Cell.EMPTY for _ in range(7)] for _ in range(6)]
        self.blue = None
        self.red = None
        self.win = None

    def down(self, row: int, col: int, cell: Cell):
        count = 0
        while row < 6 and count < 4:
            if cell == self.grid[row][col]:
                count += 1
            else:
                break
            row += 1
        return count == 4

    def check_line(self, m: int, b: int, cell: Cell):
        count = 0
        col = 0
        while col < 7 and count < 4:
            row = m * col + b
            if 0 <= row < 6:
                if cell == self.grid[row][col]:
                    count += 1
                elif count < 4:
                    count = 0
            col += 1
        return count == 4

    def load_line(self, line: str, cell):
        if re.search('^[A-G]_[A-Z][a-z]+$', line) is not None:
            idx, name = line.split('_')
            if self.red is None:
                self.red = name
            elif self.blue is None:
                self.blue = name
            elif not (name == self.blue or name == self.red):
                raise ValueError
            idx = 'ABCDEFG'.index(idx)
            name = Cell.RED if name == self.red else Cell.BLUE
            if cell != name:
                raise ValueError
            return idx, name
        else:
            raise ValueError

    def play(self, col: int, cell: Cell):
        row = 5
        while row >= 0:
            if self.grid[row][col] == Cell.EMPTY:
                self.grid[row][col] = cell
                break
            row -= 1
        if row < 0:
            raise ValueError
        if (self.down(row, col, cell)
                or self.check_line(0, row, cell)
                or self.check_line(1, row - col, cell)
                or self.check_line(-1, row + col, cell)):
            self.win = cell

    def print_grid(self):
        for row in self.grid:
            print(''.join([str(x) for x in row]))


def connect42():
    game = Connect()
    count = 0
    for line in sys.stdin:
        try:
            if game.win is None and count < 42:
                cell = Cell.RED if count % 2 == 0 else Cell.BLUE
                idx, cell = game.load_line(line[:-1], cell)
                game.play(idx, cell)
                count += 1
            else:
                raise ValueError
        except ValueError:
            print('Invalid input.')
            return
    if game.win is None:
        print('Draw.')
    else:
        print(f'{game.red if game.win == Cell.RED else game.blue}.')
    game.print_grid()


if __name__ == '__main__':
    connect42()
