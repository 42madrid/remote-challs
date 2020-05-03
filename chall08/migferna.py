#!/usr/bin/env python3

import sys

def error(message):
    print("%s: %s" % (sys.argv[0], message))

def parse_file(f):
    minifield = []
    lines = f.readlines()
    for l in lines[0:-2]:
        line = list(l.rstrip('\n'))
        minifield.append(line)
    return minifield, list(lines[-1].rstrip('\n'))

def get_pos_robot(minifield):
    for posx, line in enumerate(minifield):
        for posy, c in enumerate(line):
            if (c == 'M'):
                return posx, posy
    return -1, -1

def get_pos_exit(minifield):
    for posx, line in enumerate(minifield):
        for posy, c in enumerate(line):
            if (c == 'E'):
                return posx, posy
    return -1, -1

def move(minifield, robotx, roboty, newx, newy):
    minifield[robotx][roboty] = 0
    minifield[newx][newy] = 'M'
    return minifield

def play(minifield, instructions, robotx, roboty, robotState):
    instruction = instructions.pop(0)
    while instruction != 'I' and len(instructions) > 1:
        instruction = instructions.pop(0)
    robotState = True if instruction == 'I' else False
    get_instruction(minifield, instructions, robotx, roboty, robotState)
    print(robotState)
    

def get_instruction(minifield, instructions, robotx, roboty, robotState):
    if len(instructions) > 0:
        instruction = instructions.pop(0)
        print(instruction)
        newx = robotx
        newy = roboty
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
            move(minifield, robotx, roboty, newx , newy)
        elif minifield[newx][newy] == '*':
            return newx, newy
        get_instruction(minifield, instructions, newx, newy, robotState)
    

def main():
    minifield = []
    instructions = []
    robotState = False
    minifield, instructions = parse_file(sys.stdin)
    
    if len(sys.argv) != 1:
        return error("Invalid input.")
    robotx, roboty = get_pos_robot(minifield)
    exitx, exity = get_pos_exit(minifield)
    robotState = play(minifield, instructions, robotx, roboty, robotState)
    robotx, roboty = get_pos_robot(minifield)
    print(robotx, roboty, exitx, exity, robotState)
    if robotx == exitx and roboty == exity and not robotState:
        print('Success.')
    elif minifield[robotx][roboty] == '*':
        print('Exploded.')
    else:
        print('Failure.')

if __name__ == "__main__":
    main()