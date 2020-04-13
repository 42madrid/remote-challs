#!/usr/bin/env python3

import sys
import re


def error(e , i):
    file_name =  "stdin" if i == 0 else sys.argv[i]
    if (e == 1):
        print("%s: %s: bad format" %(sys.argv[0], file_name))
    elif (e == 2):
        print("%s: %s: Can't read file" %(sys.argv[0], file_name))
    elif (e == 3):
        print("%s: %s:  Not enough space in the given shelves" %(sys.argv[0], file_name))


# Check format plus sort shelfs
def shelf_parse(shelves):
    l = shelves.replace("\n", "").split(" ")
    l.sort(reverse=True)
    for c in l:
        if not c.isdigit():
            return None
    return (l)


# Check book format and adds books
def book_parse(books):
    b = re.search('^\d+', books)
    if b is None:
        return None
    return int(b.group())

# Placing books on shells until completed
def get_outcome(shelves, books, i):
    n_shelves = 0
    capacity = 0
    for c in shelves:
        if capacity < books:
            n_shelves += 1
            capacity += int(c)
        else:
            break
    if capacity < books:
        error(3, i)
    else:
        print(n_shelves)


def input_parse(f, i):
    books = 0
    shelves = shelf_parse(f.readline())
    for x in f:
        if shelves is None or book_parse(x) is None:
            return(error(1, i))
        books += book_parse(x)    
    f.close()
    get_outcome(shelves, books, i)


def main():
    if (len(sys.argv) > 1):
        for i in range(1, len(sys.argv)):
            try:
                print("%s:\n" % sys.argv[i] if len(sys.argv) > 2 else "", end = "")
                f = open(sys.argv[i], "r")
                input_parse(f, i)
            except:
                error(2, i)
            print("\n" if i < len(sys.argv) - 1 else "", end="")
    else:
        f = sys.stdin
        input_parse(f, 0)
    

if __name__ == "__main__":
    main()
