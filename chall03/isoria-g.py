#!/usr/bin/python3

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    isoria-g.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/09 23:50:49 by marvin            #+#    #+#              #
#    Updated: 2020/04/09 23:50:49 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def lenarg1_lenargs():
    flag1 = 0
    for i in range(len(sys.argv) - 1):
        if len(sys.argv[i + 1]) != len(sys.argv[1]):
            flag1 += 1
    return flag1

def allnum():
    flag2 = 0
    for i in range(len(sys.argv) - 1):
        if not all(c.isdigit() for c in sys.argv[i + 1]):
            flag2 += 1
    return flag2

def snail(matrix):
    res = []
    if len(matrix) == 0:
        return res
    row0 = 0
    rowy = len(matrix) - 1
    col0 = 0
    colx = len(matrix[0]) - 1

    while row0 <= rowy and col0 <= colx:
        for i in range(col0, colx+1):
            res.append(matrix[row0][i])
        row0 += 1

        for i in range(row0, rowy+1):
            res.append(matrix[i][colx])
        colx -= 1

        if row0 <= rowy:
            for i in range(colx, col0-1, -1):
                res.append(matrix[rowy][i])
        rowy -= 1

        if col0 <= colx:
            for i in range(rowy, row0-1, -1):
                res.append(matrix[i][col0])
        col0 += 1

    return res

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print ("usage: %s <1-9 squared_rows...>" % sys.argv[0])
        exit()
    elif len(sys.argv[1]) != (len(sys.argv) - 1):
        print ("usage: %s <1-9 squared_rows...>" % sys.argv[0])
        exit()
    elif len(sys.argv) > 1 and lenarg1_lenargs() != 0:
        print ("usage: %s <1-9 squared_rows...>" % sys.argv[0])
        exit()
    elif allnum() != 0:
        print ("usage: %s <1-9 squared_rows...>" % sys.argv[0])
        exit()
    else:
        mat = []
        for i in range(len(sys.argv) - 1):
            mat.append(sys.argv[i + 1])
        print(*snail(mat), sep = ", ")