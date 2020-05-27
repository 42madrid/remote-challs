#!/usr/bin/env python3

import sys
import re

COLUMNS, ROWS = "ABCDEFG", range(6)


def invalid_input() -> None:
    sys.exit("Invalid input.")


def validate_input(data: list) -> list:
    if len(data) == 1 and data[0] == "":
        sys.exit("Draw.")                                                              # Fuck this edge case
    pattern = re.compile("(^[A-G])_([A-Z][a-zA-Z0-9]+$)")
    patterns = [pattern.fullmatch(line) for line in data]
    if not all(patterns) or len(data) > 42:
        invalid_input()
    keys, teams = [p.group(1) for p in patterns], [p.group(2) for p in patterns]
    if (
        not all([keys.count(letter) <= 6 for letter in set(keys)])
        or len(set(teams)) != 2
    ):
        invalid_input()
    return data


def main() -> None:
    pieces_positions = validate_input(sys.stdin.read().split("\n"))
    lines = (                                                                          # Here we precompute all the possible
        [                                                                              # winning positions
            {(COLUMNS[i + k], ROWS[j]) for k in range(4)}
            for i in range(len(COLUMNS) - 3)
            for j in range(len(ROWS))
        ]
        + [
            {(COLUMNS[i], ROWS[j + k]) for k in range(4)}
            for i in range(len(COLUMNS))
            for j in range(len(ROWS) - 3)
        ]
        + [
            {(COLUMNS[i + k], ROWS[j + k]) for k in range(4)}
            for i in range(len(COLUMNS) - 3)
            for j in range(len(ROWS) - 3)
        ]
        + [
            {(COLUMNS[i + k], ROWS[j - k]) for k in range(4)}
            for i in range(len(COLUMNS) - 3)
            for j in range(3, len(ROWS))
        ]
    )
    players: dict = {}
    board = dict.fromkeys(COLUMNS, 0)
    for position in pieces_positions:                                                  # We compare player positions to precomputed
        column, player = position.split("_")                                           # winning positions
        pos = (column, board[column])
        board[column] += 1
        players.setdefault(player, set()).add(pos)
        if any(line <= players[player] for line in lines):
            sys.exit(f"{player}.")
    print("Draw.")


if __name__ == "__main__":
    main()
