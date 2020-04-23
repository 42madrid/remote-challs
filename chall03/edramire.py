#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

ERROR_MSG = "usage: ./edramire.py <1-9 squared_rows...>"


def snail(arr, position, limit, direction):
    while limit["left"] <= position["col"] < limit["right"] \
            and limit["top"] <= position["row"] < limit["bottom"]:
        if not (position["row"] == 0 and position["col"] == 0):
            print(", ", end="")
        print(arr[position["row"]][position["col"]], end="")
        position["row"] += direction["y"]
        position["col"] += direction["x"]
        if not (limit["left"] <= position["col"] < limit["right"]) \
                or not (limit["top"] <= position["row"] < limit["bottom"]):
            position["row"] -= direction["y"]
            position["col"] -= direction["x"]
            if direction["x"] == 1:
                limit["top"] += 1
            elif direction["x"] == -1:
                limit["bottom"] -= 1
            elif direction["y"] == 1:
                limit["right"] -= 1
            elif direction["y"] == -1:
                limit["left"] += 1
            tmp = direction["y"]
            direction["y"] = direction["x"]
            direction["x"] = -tmp
            position["row"] += direction["y"]
            position["col"] += direction["x"]
            snail(arr, position, limit, direction)
            return


def main():
    size = len(sys.argv) - 1
    if size == 0 or size != len(sys.argv[1]) or size > 20:
        print(ERROR_MSG)
        sys.exit()
    line_size = len(sys.argv[1])
    arr = []
    for k in range(1, size + 1):
        if line_size != len(sys.argv[k]) or not sys.argv[k].isdigit():
            print(ERROR_MSG)
            sys.exit()
        arr.append([])
        for c in sys.argv[k]:
            arr[k - 1].append(c)
    direction = {
        "x": 1,
        "y": 0
    }
    limits = {
        "left": 0,
        "top": 0,
        "right": line_size,
        "bottom": size
    }
    position = {
        "row": 0,
        "col": 0
    }
    snail(arr, position, limits, direction)
    print("")


if __name__ == "__main__":
    main()
