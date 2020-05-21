#!/usr/bin/python3
import sys

def errorMessage(file_name):
    print("usage: %s <1-9 squared_rows...>" % file_name)
    quit()

def validateInput(args):
    ylen = len(args) - 1
    xlen = len(args[1])
    for i in range(1, ylen + 1):
        if(len(args[i]) != ylen or len(args[i]) != xlen or not(args[i].isnumeric())):
            errorMessage(args[0])

def snailSorting(matrix, snailSort):
    length = len(matrix)
    maxlen = length * length
    i = 0
    while(i < maxlen):
        # Go right
        y = 0
        for x in range(0, len(matrix[y])):
            snailSort.append(matrix[y][x])
            i += 1
        del matrix[y]
        y += 1
        if(i >= maxlen):
            break
        # Go down
        for y in range(0, len(matrix)):
            snailSort.append(matrix[y][x])
            del matrix[y][x]
            i += 1
        y = len(matrix) - 1
        x -= 1
        if(i >= maxlen):
            break
        # Go left
        for x in range(x, -1, -1):
            snailSort.append(matrix[y][x])
            i += 1
        del matrix[y]
        if(i >= maxlen):
            break
        # Go up
        for y in range(len(matrix)-1, -1, -1):
            snailSort.append(matrix[y][x])
            del matrix[y][x]
            i += 1

if (len(sys.argv) == 1):
    errorMessage(sys.argv[0])
validateInput(sys.argv)
snailSort = []
matrix = sys.argv[1:]
for i in range(0, len(matrix)):
        matrix[i] = [int(j) for j in matrix[i]]
snailSorting(matrix, snailSort)
print(*snailSort, sep=', ')