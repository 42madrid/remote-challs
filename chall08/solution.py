#!/usr/bin/env python3

import sys


class RobotClass:
    def __init__(self, position: tuple, board: list):
        self.position = position
        self.board = board
        self.turned_on = False

    def turn_on(self):
        self.turned_on = True

    def turn_off(self):
        self.turned_on = False

    def move_north(self):
        if (
            self.turned_on
            and self.position[0] > 0
            and self.board[self.position[0] - 1][self.position[1]] != "+"
        ):
            self.position = self.position[0] - 1, self.position[1]
        self.is_in_mine()

    def move_east(self):
        if (
            self.turned_on
            and self.position[1] < len(self.board[0]) - 1
            and self.board[self.position[0]][self.position[1] + 1] != "+"
        ):
            self.position = self.position[0], self.position[1] + 1
        self.is_in_mine()

    def move_south(self):
        if (
            self.turned_on
            and self.position[0] < len(self.board) - 1
            and self.board[self.position[0] + 1][self.position[1]] != "+"
        ):
            self.position = self.position[0] + 1, self.position[1]
        self.is_in_mine()

    def move_west(self):
        if (
            self.turned_on
            and self.position[1] > 0
            and self.board[self.position[0]][self.position[1] - 1] != "+"
        ):
            self.position = self.position[0], self.position[1] - 1
        self.is_in_mine()

    def is_in_mine(self):
        if self.board[self.position[0]][self.position[1]] == "*":
            self.explode()

    def is_in_exit(self):
        return True if self.board[self.position[0]][self.position[1]] == "E" else False

    def is_turned_on(self):
        return self.turned_on

    def is_succesful(self):
        sys.exit(
            "Success."
        ) if self.is_in_exit() and not self.is_turned_on() else print(
            sys.exit("Failure.")
        )

    def explode(self):
        sys.exit("Exploded.")


def solve_maze(board: list, instructions: list):
    Robot = RobotClass(
        [(x, row.index("M")) for x, row in enumerate(board) if "M" in row][0], board
    )
    instructions_dict = {
        "N": Robot.move_north,
        "S": Robot.move_south,
        "W": Robot.move_west,
        "E": Robot.move_east,
        "I": Robot.turn_on,
        "K": Robot.turn_off,
    }
    for instruction in str(instructions[0]):
        instructions_dict[instruction]()
    Robot.is_succesful()


def invalid_input():
    sys.exit(f"{sys.argv[0]}: Invalid input.")


def validate_board(board: list):
    valid_chars = {"0", "+", "*", "M", "E"}
    if not all([len(row) == len(board[0]) for row in board]):
        return False
    if set(board[0]) - {"+", "E"} or set(board[-1]) - {"+", "E"}:
        return False
    exit_count = 0
    robot_count = 0
    for row in board:
        exit_count, robot_count = (
            exit_count + row.count("E"),
            robot_count + row.count("M"),
        )
        if (
            set(row) - valid_chars
            or (row[0] != "+" and row[0] != "E")
            or (row[-1] != "+" and row[-1] != "E")
        ):
            return False
    return exit_count == 1 and robot_count == 1


def validate_instructions(instructions: list):
    valid_chars = {"N", "S", "E", "W", "I", "K"}
    return len(instructions) == 1 and not set(instructions[0]) - valid_chars


def validate_input(data: str):
    if len(data) == 2:
        board = list(filter(None, data[0].split("\n")))
        instructions = list(filter(None, data[1].split("\n")))
        if not validate_board(board) or not validate_instructions(instructions):
            invalid_input()
        solve_maze(board, instructions)
    invalid_input()


def main():
    validate_input(sys.stdin.read().split("\n\n"))


if __name__ == "__main__":
    main()
