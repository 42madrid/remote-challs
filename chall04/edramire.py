#! /usr/bin/env python3

import sys
import fileinput


def process_file(filename):
    shelfs = []
    books = 0
    try:
        for line in fileinput.input(filename):
            shelfs_str = line.split(" ")
            if len(shelfs) == 0:
                for word in shelfs_str:
                    word = word.rstrip('\n\r')
                    if len(word) == 0:
                        continue
                    if not word.isdigit():
                        print(f"./edramire.py: {filename or 'stdin'}: Can't read file")
                        return
                    shelfs.append(int(word))
            else:
                if len(shelfs_str) <= 1 or not shelfs_str[0].isdigit():
                    print(f"./edramire.py: {filename or 'stdin'}: Can't read file")
                    return
                books += int(shelfs_str[0])
        shelfs.sort(reverse=True)
        for k in range(len(shelfs)):
            books -= shelfs[k]
            if books <= 0:
                print(k + 1)
                return
        print(f'./edramire.py: {filename or "stdin"}: Not enough space in the given shelves')
    except (PermissionError, FileNotFoundError, RuntimeError):
        print(f"./edramire.py: {filename or 'stdin'}: Can't read file")


def main():
    files = len(sys.argv) - 1
    if files == 0:
        process_file(None)
    else:
        for i in range(1, files + 1):
            if files > 1:
                print(f'{sys.argv[i]}:')
            process_file(sys.argv[i])
            if files > 1 and i < files:
                print("")


if __name__ == '__main__':
    main()
