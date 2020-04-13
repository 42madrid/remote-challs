#!/usr/bin/env python3

import sys
import collections
import os

def order(bookshelfs, books):
    bookshelfs = [int(x) for x in bookshelfs]
    bookshelfs.sort(reverse=True)
    books = sorted(books, key = lambda i: i['width'], reverse=True)
    
    for book in books:
        for i, bookshelf in enumerate(bookshelfs):
            if book['width'] <= bookshelf:
                bookshelf -= book['width']
                bookshelfs[i] = bookshelf
                break
            elif len(bookshelfs) == i + 1:
                return ("Not enough space in the given shelves")
            else:
                bookshelf + 1

    return (i+1)

def usage(message):
    print("%s: %s: %s" % (sys.argv[0], sys.argv[1], message))

def open_files(filename):
    books = []
    if (filename == os.path.basename(__file__)):
        print(usage("Can't read file"))
        return None, None
    try:
        with open(filename, "r") as file:
            for i, line in enumerate(file):
                if i == 0:
                    bookshelfs =  line.split()
                else:
                    line = line.split(" ", 1)
                    book = {
                        "width": int(line[0]),
                        "title": line[1].rstrip("\n")
                    }
                    books.append(book)
        return bookshelfs, books
    except (FileNotFoundError, PermissionError):
        usage("Can't read file")
        return None, None
    

def read():
    books = []
    for i, line in enumerate(sys.stdin):
        if '' == line.rstrip():
            break
        elif i == 0:
            bookshelfs = line.split()
        else:
            line = line.split(" ", 1)
            book = {
                "width": int(line[0]),
                "title": line[1].rstrip("\n")
            }
            books.append(book)
    return bookshelfs, books
        

def main():
    if not sys.argv[1:]:
        bookshelfs, books = read()
        print(order(bookshelfs, books))
    elif len(sys.argv[1:]) > 1:
        for filename in sys.argv[1:]:
            print(filename + ":")
            bookshelfs, books = open_files(filename)
            if bookshelfs != None and books != None:
                print(order(bookshelfs, books), end='\n\n')
    else:
        bookshelfs, books = open_files(sys.argv[1])
        if bookshelfs != None and books != None:
            print(order(bookshelfs, books))

if __name__ == "__main__":
    main()