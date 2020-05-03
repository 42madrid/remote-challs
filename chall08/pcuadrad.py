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
        '''Update the position x and y.'''
        self.x = posX
        self.y = posY
    
    def startEngine(self):
        '''Allows robot moves.'''
        self.active = True

    def stopEngine(self):
        '''Stop robot move. '''
        self.active = False

class MineField:
    def __init__(self):
        self.mines = []
        self.map = []
        self.invalidMap = True
        self.exitMark = False
        self.robotMark = False

    def setMine(self, posX, posY):
        '''Creates a new Mine object with the x and y position.'''
        self.mines.append(Mine(posX, posY))

    def setExit(self, posX, posY):
        '''Creates a new Exit object with the x and y position.'''
        self.exit = Exit(posX, posY)
        self.exitMark = True
    
    def setRobot(self, posX, posY):
        '''Creates a new Robot object with the x and y position.'''
        self.robot = Robot(posX, posY)
        self.robotMark = True

    def robotFoundExit(self) -> bool:
        '''Return True if the robot found the exit and is already stopped.'''
        if self.robot.exitFound(self.exit) and not self.robot.active:
            return True
        return False

    def verifyLine(self, line: str, pos: int, totalPos: int) -> bool:
        '''Verify a line of the map. Check that it is closed at the begining\
            and in the end. It also creates the objects that are found, and\
                if the exit is found or the robot more than once returns failure.'''
        if pos == 0 or pos + 2 == totalPos:
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
            return True
        else:
            limit = 0
            for square, posy in zip(line, range(len(line))):
                if (square == '+' and (posy == 0 or posy + 1 == len(line))):
                    limit += 1
                elif square == '0':
                    pass
                elif square == 'E':
                    limit += 1
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
        return True if limit == 2 else False

    def constructMap(self, mapi):
        '''Create the map in a two-dimensional array and check for errors.'''
        self.invalidMap = False
        for line, linePos in zip(mapi, range(len(mapi) - 1)):
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
        '''Check if the robot could move to the next x-y position.\
            Also checks in the new position if stepped a mine.'''
        if self.map[newX][newY] != '+' and self.robot.active:
            self.robot.updatePosition(newX, newY)
            self.map[befX][befY] = '0'
            self.map[newX][newY] = 'M'
            die, xMine, yMine = self.robot.explodes(self.mines)
            if die:
                sys.exit("Exploded.")

    def moveRobot(self, action: chr):
        '''Check if the command movement is valid and take the corresponding action.'''
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
        '''Receive the instruction string and process them one by one.\
            If the map is already invalid it does nothing.'''
        instr = instr.rstrip('\n')
        if not self.invalidMap:
            for command in instr:
                self.moveRobot(command)

def main():
    game = MineField()
    mapi = []
    for line in sys.stdin:
        if len(mapi) > 0 and len(mapi[-1]) == 0:
            game.constructMap(mapi)
            game.CommandsRobot(line)
        else:
            mapi.append(line[:-1])
    if game.invalidMap:
        print(f"{sys.argv[0]}: Invalid input.")
    elif game.robotFoundExit():
        print("Success.")
    else:
        print("Failure.")

if __name__ == "__main__":
    main()