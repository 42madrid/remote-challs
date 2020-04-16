#!/usr/bin/env python3

import sys

def error_message(filename, message):
    print (sys.argv[0] + ": " + filename + ": " + message)

def place_books(books, shelfs):
    rest = 0
    last_book = 0
    for i in range(0, len(shelfs)):
        begin = shelfs[i]
        begin += rest
        rest = 0
        if begin < 0 and i is len(shelfs) - 1:
            return False
        for j in range(last_book, len(books)):
            begin -= books[j]
            if begin < 0:
                rest = begin
                last_book = j + 1
                break
            if j is len(books) - 1:
                print (i + 1)
                return True
    print (i + 1)
    return True

def parse_file(txt):
    i = 0
    books = []
    shelfs_int = []
    for line in txt:
        if i is 0:
            shelfs = line.split(' ')
        else:
            line2 = line.split(' ', 1)
            books.append(int(line2[0]))
        i += 1
    [shelfs_int.append(int(i)) for i in shelfs]
    shelfs_int = sorted(shelfs_int, reverse=True)
    books = sorted(books, reverse=True)
    if not place_books(books, shelfs_int):
        return False
    else:
        return True

def parse_stdin():
    ret = []
    for line in sys.stdin:
        ret.append(line[:-1])
    return ret

def main():
    if len(sys.argv) is 1:
        if not parse_file(parse_stdin()):
            error_message("stdin", "Not enough space in the given shelves")
    else:
        for i in range(1, len(sys.argv)):
            if len(sys.argv) is not 2:
                print (sys.argv[i] + ":")
            try:
                if sys.argv[i].find(".txt") is -1:
                    error_message(sys.argv[i], "Can't read file")
                    if len(sys.argv) is not 2 and i is not len(sys.argv) - 1:
                        print()
                    continue
                file = open(sys.argv[i],'r')
            except (OSError, PermissionError):
                error_message(sys.argv[i], "Can't read file")
            else:
                content = file.read()
                if not parse_file(content.split('\n')):
                    error_message(sys.argv[i], "Not enough space in the given shelves")
                file.close()
            if len(sys.argv) is not 2 and i is not len(sys.argv) - 1:
                print()

if __name__ == "__main__":
    main()