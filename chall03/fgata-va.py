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

if (len(sys.argv) == 1):
    errorMessage(sys.argv[0])
validateInput(sys.argv)
snailSort = []
square = sys.argv[1:]
length = len(square)
if(length == 1):
    print(square[0])
    quit()
maxlen = length * length
for i in range(0, len(square)):
    square[i] = [int(j) for j in square[i]]
i = 0
while(i < maxlen):
    y = 0
    for x in range(0, len(square[y])):
        snailSort.append(square[y][x])
        i += 1
    del square[y]
    y += 1
    if(i >= maxlen):
        break
    for y in range(0, len(square)):
        snailSort.append(square[y][x])
        del square[y][x]
        i += 1
    y = len(square) - 1
    x -= 1
    if(i >= maxlen):
        break
    for x in range(x, -1, -1):
        snailSort.append(square[y][x])
        i += 1
    del square[y]
    if(i >= maxlen):
        break
    for y in range(len(square)-1, -1, -1):
        snailSort.append(square[y][x])
        del square[y][x]
        i += 1
print(*snailSort, sep=', ')