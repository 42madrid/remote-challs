#!/usr/bin/env python3

import sys

def validate_input(data: str):
    instructions = list(filter(None, data))
    print(instructions)

def main():
    validate_input(sys.stdin.read().split("\n"))

if __name__ == "__main__":
    main()
