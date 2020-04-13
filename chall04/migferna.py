#!/usr/bin/env python3

import sys
import collections

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
            else:
                bookshelf + 1
    return (i+1)

def open_files():
    books = []
    try:
        with open(sys.argv[1], "r") as file:
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
        print("./%s: %s: Can't read file" % (sys.argv[0], sys.argv[1]))
    

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
    else:
        bookshelfs, books = open_files()
    print(order(bookshelfs, books))

if __name__ == "__main__":
    main()