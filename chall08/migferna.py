#!/usr/bin/env python3

import sys

def first_and_last(line):
    for c in line:
        if c != '+':
            return False
    return True

def check_line(line):
    if (line[0] != '+' and line[0] != 'E') or (line[-1] != '+' and line[-1] != 'E'):
        return False
    for c in line[1:-1]:
        if c != '*' and c != '0' and c != '+' and c != 'M' and c != 'E':
            return False
    return True

def check(minifield):
    robotx, roboty = valid_robot(minifield)
    exitx, exity = valid_exit(minifield)
    first = first_and_last(minifield[0])
    for l in minifield:
        checked = check_line(l)
        if not checked:
            return False
    last = first_and_last(minifield[-1])

    if robotx == -1 or exitx == -1 or not first or not last:
        return False
    else:
        return True

def parse_file(f):
    minifield = []
    lines = f.readlines()
    for l in lines[0:-2]:
        line = list(l.rstrip('\n'))
        minifield.append(line)
    return minifield, list(lines[-1].rstrip('\n'))

def valid_robot(minifield):
    found = False
    robotx = -1
    roboty = -1
    for posx, line in enumerate(minifield):
        for posy, c in enumerate(line):
            if c == 'M' and found:
                return -1, -1
            elif c == 'M':
                robotx = posx
                roboty = posy
    return robotx, roboty

def valid_exit(minifield):
    found = False
    exitx = -1
    exity = -1
    for posx, line in enumerate(minifield):
        for posy, c in enumerate(line):
            if c == 'E' and found:
                return -1, -1
            elif c == 'E':
                exitx = posx
                exity = posy
    return exitx, exity

def move(minifield, robotx, roboty, newx, newy):
    minifield[robotx][roboty] = 0
    minifield[newx][newy] = 'M'
    return minifield

def play(minifield, instructions, robotx, roboty, robotState):
    instruction = instructions.pop(0)
    while instruction != 'I' and len(instructions) > 1:
        instruction = instructions.pop(0)
    robotState = True if instruction == 'I' else 0
    robotState, newx, newy = get_instruction(minifield, instructions, robotx, roboty, robotState)
    return robotState, newx, newy

def get_instruction(minifield, instructions, robotx, roboty, robotState):
    newx = robotx
    newy = roboty
    if len(instructions) > 0:
        instruction = instructions.pop(0)
        if instruction == 'N' and robotState:
            newx = newx - 1
            newy = newy
        elif instruction == 'S' and robotState:
            newx = newx + 1
            newy = newy
        elif instruction == 'E' and robotState:
            newx = newx
            newy = newy + 1
        elif instruction == 'W' and robotState:
            newx = newx
            newy = newy - 1
        elif instruction == 'K':
            robotState = False
        elif instruction == 'I':
            robotState = True
        
        if minifield[newx][newy] == '0' or minifield[newx][newy] == 'E':
            move(minifield, robotx, roboty, newx, newy)
        elif minifield[newx][newy] == '+':
            move(minifield, robotx, roboty, robotx, roboty)
        elif minifield[newx][newy] == '*':
            return robotState, newx, newy
        robotState, newx, newy = get_instruction(minifield, instructions, newx, newy, robotState)
    return robotState, newx, newy
    

def main():
    minifield = []
    instructions = []
    robotState = False
    if len(sys.argv) != 1:
        return 
    minifield, instructions = parse_file(sys.stdin)
    if not check(minifield):
        print("%s: Invalid input." % (sys.argv[0]))
        return
    robotx, roboty = valid_robot(minifield)
    exitx, exity = valid_exit(minifield)
    robotState, newx, newy = play(minifield, instructions, robotx, roboty, robotState)
    robotx, roboty = valid_robot(minifield)
    if robotx == exitx and roboty == exity and not robotState:
        print("Success.")
    elif minifield[newx][newy] == '*':
        print("Exploded.")
    else:
        print("Failure.")

if __name__ == "__main__":
    main()