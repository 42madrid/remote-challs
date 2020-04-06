#!/usr/bin/python3

import sys

# Make a dictionary widh all the morse letters Keys are alphabetic, values are morse and items are all

MORSE = {
    'A':'.-',
    'B':'-...',
    'C':'-.-.',
    'D':'-..',
    'E':'.',
    'F':'..-.',
    'G':'--.',
    'H':'....',
    'I':'..',
    'J':'.---',
    'K':'-.-',
    'L':'.-..',
    'M':'--',
    'N':'-.',
    'O':'---',
    'P':'.--.',
    'Q':'--.-',
    'R':'.-.',
    'S':'...',
    'T':'-',
    'U':'..-',
    'V':'...-',
    'W':'.--',
    'X':'-..-',
    'Y':'-.--',
    'Z':'--..',
    ' ': ' '
}

# Control the cases of less or more arguments than demanded
# Control isalpha or spaces
# Turn to upper
# for each char or space in the string write the corresponding char of our dictionary

def main():
    if len(sys.argv) == 2 and all(x.isalpha() or x.find(' ') for x in sys.argv[1]):
        str = sys.argv[1].upper()
        for char in str:
            if (char.isalpha() or char == ' '):
                sys.stdout.write(MORSE[char])
    else:
        print ("usage: ./antomart.py <a-zA-Z string>")
if __name__ == "__main__":
     main()