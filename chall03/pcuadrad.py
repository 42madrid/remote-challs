#!/usr/bin/env python

import sys

def error():
    print ("usage: " + sys.argv[0] + " <1-9 squared_rows...>")
    exit(1)

def snail(array):
    snailArray = []
    rowBegin = 0
    rowEnd = len(array) - 1
    colBegin = 0
    colEnd = len(array[0]) - 1
    while rowBegin <= rowEnd and colBegin <= colEnd:
        for col in range(colBegin, colEnd + 1):
            snailArray.append(array[rowBegin][col])
        rowBegin += 1
        for row in range(rowBegin, rowEnd + 1):
            snailArray.append(array[row][colEnd])
        colEnd -= 1
        for col in range(colEnd, colBegin - 1, -1):
            snailArray.append(array[rowEnd][col])
        rowEnd -= 1
        for row in range(rowEnd, rowBegin - 1, -1):
            snailArray.append(array[row][colBegin])
        colBegin += 1
    print(', '.join(snailArray))

def check(array):
    for elem in array:
        if len(elem) != len(array) or elem.isdigit() == False:
            return False
    return True

def main():
    array = []
    for i in range(1, len(sys.argv)):
        array.append(sys.argv[i])
    if len(array) == 0 or len(array) > 20 or check(array) == False:
        error()
    snail(array)

if __name__ == "__main__":
    main()
