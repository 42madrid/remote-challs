#!/usr/bin/env python3

import sys
import collections
import os

def order(bookshelfs, books):
    bookshelfs = [int(x) for x in bookshelfs]
    bookshelfs.sort(reverse=True)
    books = sorted(books, key = lambda i: i['width'], reverse=True)
    
    i = 0
    for book in books:
        for i, bookshelf in enumerate(bookshelfs):
            if book['width'] <= bookshelf:
                bookshelf -= book['width']
                bookshelfs[i] = bookshelf
                break
            elif len(bookshelfs) == i + 1:
                return
            else:
                bookshelf + 1
    return i if len(bookshelfs) == 0 else i+1

def usage(message):
    if (len(sys.argv) > 1):
        print("%s: %s: %s" % (sys.argv[0], sys.argv[1], message))
    else:
        print("%s: stdin: %s" % (sys.argv[0], message))

def open_files(filename):
    books = []
    bookshelfs = []
    if (filename == os.path.basename(__file__)):
        return bookshelfs, books
    try:
        with open(filename, "r") as file:
            for i, line in enumerate(file):
                if i == 0:
                    bookshelfs =  line.split()
                    bookshelfs = [s for s in bookshelfs if s.isdigit()]
                else:
                    line = line.split(" ", 1)
                    book = {
                        "width": int(line[0]),
                        "title": line[1].rstrip("\n")
                    }
                    books.append(book)
        return bookshelfs, books
    except (FileNotFoundError, PermissionError, ValueError, IndexError):
        return bookshelfs, books
    

def read():
    books = []
    bookshelfs = []
    for i, line in enumerate(sys.stdin):
        if '' == line.rstrip():
            return bookshelfs, books
        elif i == 0:
            bookshelfs = line.split()
            bookshelfs = [s for s in bookshelfs if s.isdigit()]
        else:
            try:
                line = line.split(" ", 1)
                book = {
                    "width": int(line[0]),
                    "title": line[1].rstrip("\n")
                }
                books.append(book)
            except (ValueError, IndexError):
                return bookshelfs, books
    return bookshelfs, books
        

def main():
    if not sys.argv[1:]:
        bookshelfs, books = read()
        if len(bookshelfs) > 0 and len(books) > 0:
            output = order(bookshelfs, books)
            if output != None:
                print(output)
            else:
                usage("Not enough space in the given shelves")
        else:
            usage("Can't read file")
    elif len(sys.argv[1:]) > 1:
        for i, filename in enumerate(sys.argv[1:]):
            print(filename + ":")
            bookshelfs, books = open_files(filename)
            if len(bookshelfs) > 0 and len(books) > 0:
                output = order(bookshelfs, books)
                if output != None:
                    print(output)
                else:
                    usage("Not enough space in the given shelves")
            else:
                usage("Can't read file")
            print("\n" if i < len(sys.argv) - 2 else "", end="")
    else:
        bookshelfs, books = open_files(sys.argv[1])
        if len(bookshelfs) > 0 and len(books) > 0:
            output = order(bookshelfs, books)
            if output != None:
                print(output)
            else:
                usage("Not enough space in the given shelves")
        else:
            usage("Can't read file")

if __name__ == "__main__":
    main()