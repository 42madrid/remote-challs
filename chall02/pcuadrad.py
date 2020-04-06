#!/usr/bin/env python

import sys

def finish_program():
    print ("usage: ./pcuadrad.py <a-zA-Z string>")
    sys.exit()

def check_string(txt):
    for char in txt:
        if not char.isalpha() and not char.isspace():
            return 0
    return 1

def parse_morse(txt):
    morse = {
        "A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".", "F": "..-.",
        "G": "--.", "H": "....", "I": "..", "J": ".---", "K": "-.-", "L": ".-..",
        "M": "--", "N": "-.", "O": "---", "P": ".--.", "Q": "--.-", "R": ".-.",
        "S": "...", "T": "-", "U": "..-", "V": "...-", "W": ".--", "X": "-..-",
        "Y": "-.--", "Z": "--..", " ": " "
    }
    str_morse = ""
    for char in txt:
        str_morse += morse.get(char)
    return str_morse

if __name__ == "__main__":
    if len(sys.argv) != 2:
        finish_program()
    elif check_string(sys.argv[1]) == 0:
        finish_program()
    print (parse_morse(sys.argv[1].upper()))
