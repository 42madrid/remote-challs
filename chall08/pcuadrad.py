#!/usr/bin/env python3
import sys

class Object:
    def __init__(self, posX: int, posY: int):
        self.x = posX
        self.y = posY

class Mine(Object):
    def __init__(self, posX, posY):
        super().__init__(posX, posY)

class Exit(Object):
    def __init__(self, posX, posY):
        super().__init__(posX, posY)

class Robot(Object):
    def __init__(self, posX, posY):
        super().__init__(posX, posY)
        self.active = False

    def explodes(self, mines: list) -> bool:
        '''Return True if the robot has stepped on a mine.'''
        for mine in mines:
            if self.x == mine.x and self.y == mine.y:
                return True, mine.x, mine.y
        return False, 0, 0

    def exitFound(self, oExit: Exit) -> bool:
        '''Return true if the robot found the exit.'''
        if self.x == oExit.x and self.y == oExit.y:
            return True
        return False
    
    def updatePosition(self, posX, posY):
        self.x = posX
        self.y = posY
    
    def startEngine(self):
        self.active = True

    def stopEngine(self):
        self.active = False

class MineField:
    def __init__(self):
        self.mines = []
        self.map = []
        self.invalidMap = False
        self.exitMark = False
        self.robotMark = False

    def setMine(self, posX, posY):
        self.mines.append(Mine(posX, posY))

    def setExit(self, posX, posY):
        self.exit = Exit(posX, posY)
        self.exitMark = True
    
    def setRobot(self, posX, posY):
        self.robot = Robot(posX, posY)
        self.robotMark = True

    def robotFoundExit(self) -> bool:
        if self.robot.exitFound(self.exit) and not self.robot.active:
            return True
        return False

    def verifyLine(self, line: str, pos: int, totalPos: int) -> bool:
        if pos == 0 or pos + 1 == totalPos:
            for square, posy in zip(line, range(len(line))):
                if square == '+':
                    pass
                elif square == 'E':
                    if not self.exitMark:
                        self.setExit(pos, posy)
                    else:
                        return False
                else:
                    return False
        else:
            for square, posy in zip(line, range(len(line))):
                if (square == '+' and (posy == 0 or posy + 1 == len(line))) or square == '0':
                    pass
                elif square == 'E':
                    if not self.exitMark:
                        self.setExit(pos, posy)
                    else:
                        return False
                elif square == '*':
                    self.setMine(pos, posy)
                elif square == 'M':
                    if not self.robotMark:
                        self.setRobot(pos, posy)
                    else:
                        return False
                else:
                    return False
        return True

    def constructMap(self, mapi):
        for line, linePos in zip(mapi, range(len(mapi))):
            if linePos > 0 and len(line) != len(lastLine):
                self.invalidMap = True
            if self.verifyLine(line, linePos, len(mapi)):
                self.map.append([char for char in line])
            else:
                self.invalidMap = True
            lastLine = line
        if not self.robotMark or not self.exitMark:
            self.invalidMap = True

    def makeRobotMove(self, befX, befY, newX, newY):
        if self.map[newX][newY] != '+' and self.robot.active:
            self.robot.updatePosition(newX, newY)
            self.map[befX][befY] = '0'
            self.map[newX][newY] = 'M'
            die, xMine, yMine = self.robot.explodes(self.mines)
            if die:
                sys.exit(f"\nExploded by the Mine[{xMine}][{yMine}].")

    def moveRobot(self, action: chr):
        xBefore = self.robot.x
        yBefore = self.robot.y
        if action == 'I':
            self.robot.startEngine()
        elif action == 'K':
            self.robot.stopEngine()
        elif action == 'N':
                self.makeRobotMove(xBefore, yBefore, self.robot.x - 1, self.robot.y)
        elif action == 'S':
            self.makeRobotMove(xBefore, yBefore, self.robot.x + 1, self.robot.y)
        elif action == 'E':
            self.makeRobotMove(xBefore, yBefore, self.robot.x, self.robot.y + 1)
        elif action == 'W':
            self.makeRobotMove(xBefore, yBefore, self.robot.x, self.robot.y - 1)
        else:
            self.invalidMap = True
    
    def CommandsRobot(self, instr: str):
        if not self.invalidMap:
            for command in instr:
                self.moveRobot(command)

def main():
    game = MineField()
    mapi = []
    for line in sys.stdin:
        mapi.append(line[:-1])
    game.constructMap(mapi)
    print("\nCommands: ", end='')
    for line in sys.stdin:
        game.CommandsRobot(line)
    print()
    if game.invalidMap:
        print(f"{sys.argv[0]}: Invalid input.")
    elif game.robotFoundExit():
        print("Success.")
    else:
        print("Failure.")

if __name__ == "__main__":
    main()