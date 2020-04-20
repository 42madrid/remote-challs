#!/usr/bin/env python3

import sys
from itertools import islice, permutations


def error(filename, message):
    print("%s: %s: %s" % (sys.argv[0], filename, message))


def parse_file(f):
    shelves = [int(shelf) for shelf in f.readline()[:-1].split()]
    books = [int(line[: line.index(" ")]) for line in f.readlines()]
    shelves.sort(reverse=True)
    books.sort(reverse=True)
    return shelves, books


def parse_input(f):
    if isinstance(f, str):
        with open(f, "r") as fd:
            return parse_file(fd)
    return parse_file(f)


def strict_search(shelves, books):
    used_shelves = 1
    shelves = iter(shelves)
    shelf = next(shelves)
    for book in books:
        if shelf >= book:
            shelf -= book
        else:
            try:
                shelf = next(shelves)
                used_shelves += 1
                if shelf < book:
                    break
            except StopIteration:
                break
    else:
        return used_shelves


def permissive_search(shelves, books):
    shelves_copy = list(shelves)
    for book in books:
        if book > max(shelves_copy):
            break
        for i, s in enumerate(shelves_copy):
            if book <= s:
                shelves_copy[i] -= book
                break
    else:
        return len([s for i, s in enumerate(shelves_copy) if s != shelves[i]])


def simulate_shelves(shelves, books, permissive=False):
    search = permissive_search if permissive else strict_search
    for book_ordering in islice(permutations(books), 1000000):
        used_shelves = search(list(shelves), book_ordering)
        if used_shelves is not None:
            yield used_shelves


def bookshelf_problem(filename=None, permissive=False):
    try:
        shelves, books = parse_input(filename if filename is not None else sys.stdin)
        solutions = set(simulate_shelves(shelves, books, permissive=permissive))
        if not solutions:
            return error(filename if filename is not None else "stdin", "Not enough space in the given shelves")
        print(solutions if permissive else min(solutions))
    except Exception as e:
        print(e)
        error(filename if filename is not None else "stdin", "Can't read file")


def main():
    permissive = "--permissive" in sys.argv
    if permissive:
        sys.argv.pop(sys.argv.index("--permissive"))
    if len(sys.argv) < 2:
        return bookshelf_problem(permissive=permissive)
    if len(sys.argv) < 3:
        return bookshelf_problem(filename=sys.argv[1], permissive=permissive)
    for arg in sys.argv[1:]:
        print(f"{arg}:")
        bookshelf_problem(filename=arg, permissive=permissive)


if __name__ == "__main__":
    main()
