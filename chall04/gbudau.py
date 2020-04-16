#!/usr/bin/env python3

import sys

STDIN = 0
FILE = 1

def read_error(filename):
    print("{}: {}: Can't read file".format(sys.argv[0], filename))

def space_error(filename):
    print("{}: {}: Not enough space in the given shelves".format(sys.argv[0], filename))

def fill_bookshelves(filename, bookshelves, books):
    # Convert books and bookshelves to integers
    # Sort from max to min
    books = [int(i) for i in books]
    bookshelves = [int(i) for i in bookshelves]
    books.sort(reverse = True)
    bookshelves.sort(reverse = True)

    used_bookshelves = []
    while books and bookshelves and ((bookshelves[0] >= books[0]) or (used_bookshelves and used_bookshelves[0] >= books[0])):
        if  used_bookshelves and used_bookshelves[0] >= books[0]:
            used_bookshelves[0] -= books[0]
            books.pop(0)
            used_bookshelves.sort(reverse = True)
        else:
            used_bookshelves.append(bookshelves[0] - books[0])
            used_bookshelves.sort(reverse = True)
            books.pop(0)
            bookshelves.pop(0)

    space_error(filename) if books else print(len(used_bookshelves))

def verify_and_save_file(arg, source):
    bookshelves = []
    books = []

    # Save first line to bookshelves list from the file generator, striping spaces and newline
    # Splitting the line into a list of numeric strings
    # next() can return an error when the file is empty, without any newline so im using try/except
    # Also checking the shelves to have non-zero values
    try:
        bookshelves = next(arg).rstrip().split()
        if not bookshelves or any(not shelf.isdigit() or shelf[0] == '0' for shelf in bookshelves):
            return None, None
    except StopIteration:
        if source == STDIN:
            read_error("stdin")
            sys.exit(0)
        else: return None, None 

    # Save first word from each line starting from second line into books list
    # Checking if they are numeric and not empty
    for line in arg:
        books += line.rstrip().split()[:1]
    if not books or any(not book.isdigit() for book in books):
        return None, None
    return bookshelves, books

def main():
    # Input come from buffer and not direct input, accepting heredoc only
    if not sys.stdin.isatty():
        bookshelves, books = verify_and_save_file(sys.stdin, STDIN)
        if (not bookshelves or not books):
            read_error("stdin")
        else:
            fill_bookshelves("stdin", bookshelves, books)
        sys.exit(0)

    # Running the script without input, treating this case as read error
    if len(sys.argv) == 1:
        read_error("stdin")

    # Iterate over arguments, check for IO error, verify file and process
    for i, arg in enumerate(sys.argv[1:], start=2):
        try:
            with open(arg) as f:
                bookshelves, books = verify_and_save_file(f, FILE)
                len(sys.argv) > 2 and print(arg, end=':\n')
                if (not bookshelves or not books):
                    read_error(arg)
                    i < len(sys.argv) and print()
                else:
                    fill_bookshelves(f.name, bookshelves, books)
                    i < len(sys.argv) and print()
        except IOError:
            len(sys.argv) > 2 and print(arg, end=':\n')
            read_error(arg)
            i < len(sys.argv) and print()

if __name__ == '__main__':
    main()
