#!/usr/bin/env python3
import sys
import curses.ascii

def usage():
    sys.exit(f"usage: {sys.argv[0]} <1-9 squared_rows...>")

# Check if argument count is between 1 and 20
def check_argc(count):
    return count > 0 and count < 21

# Check if string has the same length as count and is made of ascii digits
def isalphanum_len(string, count):
    length = 0
    for letter in string:
        if not curses.ascii.isdigit(letter) or length > count:
            return False
        length += 1
    return length == count

# Validate all arguments
def check_each_arg(args, count):
    for arg in args:
        if not isalphanum_len(arg, count):
            return False
    return True

# Error checking: valid number of command-line arguments, format and length of arguments
def check_errors(args, count):
    if not check_argc(count) or not check_each_arg(args, count):
        usage()

# Print digits in the matrix starting from outside, clockwise
# Using slicing to manage length or order of printing
# Increment rows and start of square and decrement count
def print_snail(args, count):
    start = 0
    row = 0
    while row < count:
        for digit in args[row][start:count:]:
            print(digit, end=', ') if row + 1 != count else print(digit)
        row += 1
        if row == count:
            break
        for arg in args[row:count - 1]:
            print(arg[count - 1], end=', ')
        for digit in args[count - 1][start + 1:count:][::-1]:
            print(digit, end=', ')
        print(args[count - 1][start], end=', ') if row + 1 != count else print(args[count - 1][start])
        count -= 1
        for arg in args[row:count:][::-1]:
            print(arg[start], end=', ')
        start += 1

# Error management then print the square array in spiral, clowckwise, starting from outside
def main():
    check_errors(sys.argv[1:], len(sys.argv) - 1)
    print_snail(sys.argv[1:], len(sys.argv) - 1)

if  __name__ == "__main__":
    main()
