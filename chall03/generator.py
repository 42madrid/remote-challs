#!/usr/bin/env python3

import sys
from random import randrange

def usage():
    print("usage: %s <length>" % sys.argv[0])


def generate(length):
    return " ".join("".join(str(randrange(1, 9)) for _ in range(length)) for _ in range(length))


def main():
    if len(sys.argv) != 2 or not sys.argv[1].isnumeric():
        return usage()
    print(generate(int(sys.argv[1])))

if __name__ == "__main__":
    main()
