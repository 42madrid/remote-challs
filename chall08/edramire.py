#! /usr/bin/env python3

import sys


class Minefield:
    def __init__(self):
        self.rows = 0
        self.cols = 0
        self.lines = []
        self.loaded = False
        self.exit = None
        self.robot = None
        self.valid = True

    def validate(self, line_str: str):
        len_line = len(line_str)
        if len_line < 3 or (self.rows > 0 and len_line != self.cols):
            return False
        if any(c not in '+*ME0' for c in line_str):
            return False
        e = sum((1 if c == 'E' else 0 for c in line_str), 0)
        if e > 1 or (e == 1 and self.exit is not None):
            return False
        m = sum((1 if c == 'M' else 0 for c in line_str[1:len_line]), 0)
        if m > 1 or (m == 1 and self.robot is not None):
            return False
        if all(c in '+E' for c in line_str):
            if e == 1 and (line_str.startswith('E') or line_str.endswith('E')):
                return False
            if (self.rows > 1
                    and all(c in '+E' for c in self.lines[self.rows - 1])):
                return False
        elif all(c in 'M0*' for c in line_str[1:len_line - 1]):
            if line_str[0] not in '+E' or line_str[-1] not in '+E':
                return False
        else:
            return False
        return True

    def is_valid_position(self, row: int, col: int):
        if (row < 0 or row >= self.rows or col < 0 or col >= self.cols
                or self.lines[row][col] == '+'):
            return False
        return True

    def position_has_bomb(self, row, col):
        if self.lines[row][col] == '*':
            return True
        return False

    def is_exit(self, row, col):
        if row == self.exit[0] and col == self.exit[1]:
            return True
        return False

    def __repr__(self):
        return f'{self.lines}\n{self.robot}\n{self.exit}'


class Robot:
    moves = {
        'N': (-1, 0),
        'E': (0, 1),
        'S': (1, 0),
        'W': (0, -1)
    }

    def __init__(self, row, col):
        self.row = row
        self.col = col
        self.on = False
        self.destroyed = False

    def move(self, mine_field: Minefield, c: str):
        if c == 'I':
            self.on = True
        elif c == 'K':
            self.on = False
        elif self.on:
            row = self.row + Robot.moves[c][0]
            col = self.col + Robot.moves[c][1]
            if mine_field.is_valid_position(row, col):
                self.row = row
                self.col = col
                if mine_field.position_has_bomb(row, col):
                    self.destroyed = True

    def on_exit(self, mine_field: Minefield):
        if not self.on and mine_field.is_exit(self.row, self.col):
            return True
        return False


def read_lines():
    lines = None
    for line in sys.stdin:
        if lines is None:
            lines = []
        line = line.rstrip('\n')
        if len(lines) > 0 and len(lines[-1]) == 0:
            minefield = Minefield()
            for row in lines[:-1]:
                if minefield.validate(row):
                    if minefield.rows == 0:
                        minefield.cols = len(row)
                    if 'E' in row:
                        minefield.exit = (minefield.rows, row.index('E'))
                    if 'M' in row:
                        minefield.robot = (minefield.rows, row.index('M'))
                        line = line.replace('M', '0')
                    minefield.rows += 1
                    minefield.lines.append(row)
                else:
                    minefield.valid = False
                    break
            if (minefield.valid and minefield.exit and minefield.robot
                    and len(line) > 0 and all(c in 'NESWIK' for c in line)):
                robot = Robot(*minefield.robot)
                for c in line:
                    robot.move(minefield, c)
                    if robot.destroyed:
                        print('Exploted.')
                        break
                if not robot.destroyed:
                    if robot.on_exit(minefield):
                        print('Success.')
                    else:
                        print('Failure.')
            else:
                print('Invalid input.')
            lines = None
        else:
            lines.append(line)


if __name__ == '__main__':
    read_lines()
