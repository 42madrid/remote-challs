#!/usr/bin/python3

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    isoria-g.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 21:23:38 by marvin            #+#    #+#              #
#    Updated: 2020/04/13 21:23:38 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os

def findnum():
    totalsize = 0
    for item in sizes:
        totalsize = totalsize + item
    return (totalsize // maxshelf + 1)

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print ("%s: not_existing_file: Can't read file" % sys.argv[0])
        exit()
    elif len(sys.argv) == 2:
        if (os.access('sys.argv[1]', os.R_OK)) == True:
            print ("%s: permission_denied_file: Can't read file" % sys.argv[0])
            exit()
        else:
            file_object = open(sys.argv[1], "r")
            lines = file_object.readlines()
            file_object.close()
            maxshelf = 0
            for item in map(int, lines[0].split()):
                if item > maxshelf:
                    maxshelf = item
            sizes = []
            for i in range(len(lines) - 1):
                sizebook = lines[i + 1].split()
                sizes.append(int(sizebook[0]))
            maxbook = 0
            for item in sizes:
                if item > maxbook:
                    maxbook = item
            if maxbook > maxshelf:
                print ("%s: permission_denied_file: Not enough space in the given shelves" % sys.argv[0])
                exit()
            else:
                print(findnum())
    elif len(sys.argv) > 2:
        for i in range(len(sys.argv) - 1):
            print("%s:", sys.argv[i + 1])
            file_object = open(sys.argv[i + 1], "r")
            lines = file_object.readlines()
            file_object.close()
            maxshelf = 0
            for item in map(int, lines[0].split()):
                if item > maxshelf:
                    maxshelf = item
            sizes = []
            for i in range(len(lines) - 1):
                sizebook = lines[i + 1].split()
                sizes.append(int(sizebook[0]))
            maxbook = 0
            for item in sizes:
                if item > maxbook:
                    maxbook = item
            if maxbook > maxshelf:
                print ("%s: permission_denied_file: Not enough space in the given shelves" % sys.argv[0])
                exit()
            else:
                print(findnum())
        exit()
    else:
        exit()