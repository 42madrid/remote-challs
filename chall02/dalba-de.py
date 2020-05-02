#!/usr/bin/env python
# -*- coding: utf-8 -*-

dictionary = {"a": ".-", "b": "-...", "c": "-.-.", "d": "-..", "e": ".", "f": "..-.", 
    "g": "--.", "h": "....", "i": "..", "j": "·---", "k": "-.-", "l": ".-..", 
    "m": "--", "n": "-.", "o": "---", "p": ".--.", "q": "--.-",
    "r": ".-.", "s": "...", "t": "-", "u": "..-", "v": "...-", "w": ".--",
    "x": "-..-", "y": "-.--", "z": "--..",
    "A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".", "F": "..-.", 
    "G": "--.", "H": "....", "I": "..", "J": "·---", "K": "-.-", "L": ".-..", 
    "M": "--", "N": "-.", "O": "---", "P": ".--.", "Q": "--.-",
    "R": ".-.", "S": "...", "T": "-", "U": "..-", "V": "...-", "W": ".--",
    "X": "-..-", "Y": "-.--", "Z": "--.."}

import sys

texto = ""

if len(sys.argv) == 2:
    if len(sys.argv[1]) == 0:
        print "usage: ./dalba-de.py <a-zA-Z string>"
        sys.exit()
    for c in sys.argv[1]:
        if c in dictionary:
            texto += dictionary[c]
        elif c == " ":
            texto += " "
        else:
            print "usage: ./dalba-de.py <a-zA-Z string>"
            sys.exit()
    print texto
else:
    print "usage: ./dalba-de.py <a-zA-Z string>"
