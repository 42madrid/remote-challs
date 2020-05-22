#!/usr/bin/env python
import sys
import re

class Position:
    def __init__(self, box):
        for lines in box:
            if "m" in lines:
                self.x = lines.index("m")
                self.y = box.index(lines)
    def next_pos(self, move, box, started):
        if started:
            if move == "n" and self.y > 0 and self.get_square(box, self.x, self.y - 1) != "+":
                self.y = self.y - 1
            if move == "s" and self.y < len(box) - 1 and self.get_square(box, self.x, self.y + 1) != "+":
                self.y = self.y + 1
            if move == "e" and self.x < len(box[0]) - 2 and self.get_square(box, self.x + 1, self.y) != "+":                
                self.x = self.x + 1
            if move == "w" and self.x > 0 and self.get_square(box, self.x - 1, self.y) != "+":
                self.x = self.x - 1
    def get_square(self, box, x, y):
        return box[y][x]


def check_box(box):
    count_m = 0
    count_e = 0
    count_upper = 0
    for lines in range(len(box)):
        count_m += box[lines].count("m")
        count_e += box[lines].count("e")
        if len(box[lines]) != len(box[0]) and box[lines] != '\n':
            return 0
        if re.match(r"^\+\+*\+$", box[lines]) or re.match(r"^\+[\+e]*\+$", box[lines]):
            count_upper += 1
        elif box[lines] == '\n':
            if lines != len(box) - 1:
                return 0
        elif not re.match(r"^[\+e][0*m]*[\+e]$", box[lines]):
            return 0
    return 1 if count_e == 1 and count_m == 1 and count_upper == 2 else 0
        

box = []
instructions = []
position = []
started = False
result = 0
for line in sys.stdin:
    line = line.lower()
    if re.match(r"^[\+e][0*em+]*[\+e]$", line) or line == '\n':
        box.append(line)    
    elif re.match(r"^[nsewik]*$", line):
        instructions.append(line)
    else:
        instructions.append("-1")
if not (instructions.count("-1") > 0 or len(instructions) != 1 or check_box(box) != 1):
    pos = Position(box)
    for move in instructions[0]:
        if move == "i":
            started = True
        elif move == "k":
            started = False
        else:
            pos.next_pos(move, box, started)
        result = 0
        if pos.get_square(box, pos.x, pos.y) == "*":
            print("Exploded.")
            exit()
        if pos.get_square(box, pos.x, pos.y) == "e" and not started:
            print("Success.")
            exit()
    print("Failure.")
else:
    print("./szavarce.py: Invalid input.")