#!/usr/bin/env python3

import sys
import re


def error(e , i):
    file_name =  "stdin" if i == 0 else sys.argv[i]
    if (e == 1):
        print("%s: %s: Bad format" %(sys.argv[0], file_name))
    elif (e == 2):
        print("%s: %s: Can't read file" %(sys.argv[0], file_name))
    elif (e == 3):
        print("%s: %s: Not enough space in the given shelves" %(sys.argv[0], file_name))


# Check format plus sort shelves
def shelf_parse(shelves):
    l = shelves.replace("\n", "").split(" ")
    l.sort(key=len, reverse=True)
    for c in l:
        if not c.isdigit():
            return None
    return (l)


# Check book format and add books
def book_parse(books):
    b = re.search('^\d+', books)
    if re.search('^\d+\s\w+', books) is None:
        return None
    return int(b.group())


# Calculate number of shelves: placing books on shells until completed
def calc_number(shelves, books, i):
    n_shelves = 0
    capacity = 0
    for c in shelves:
        capacity += int(c)
        n_shelves += 1
        if capacity >= books:
            break
    if capacity < books:
        error(3, i)
    else:
        print(n_shelves)


# Get number of shelves, prior parsing info
def number_of_shelves(f, i):
    books = 0
    shelves = shelf_parse(f.readline())
    for x in f:
        if shelves is None or book_parse(x) is None:
            return(error(1, i))
        books += book_parse(x)    
    f.close()
    if books == 0:
        error(1, i)
    else:
        calc_number(shelves, books, i)


def main():
    l = len(sys.argv)
    if (l > 1):
        for i in range(1, l):
            try:
                print("%s:\n" % sys.argv[i] if l > 2 else "", end = "")
                f = open(sys.argv[i], "r")
                number_of_shelves(f, i)
            except:
                error(2, i)
            print("\n" if i < l - 1 else "", end="")
    else:
        f = sys.stdin
        number_of_shelves(f, 0)
    

if __name__ == "__main__":
    main()
