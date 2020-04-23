#!/usr/bin/env python

import sys
import re

morse = {
	"A": ".-",
	"B": "-...",
	"C": "-.-.",
	"D": "-..",
	"E": ".",
	"F": "..-.",
	"G": "--.",
	"H": "....",
	"I": "..",
	"J": ".---",
	"K": "-.-",
	"L": ".-..",
	"M": "--",
	"N": "-.",
	"O": "---",
	"P": ".--.",
	"Q": "--.-",
	"R": ".-.",
	"S": "...",
	"T": "-",
	"U": "..-",
	"V": "...-",
	"W": ".--",
	"X": "-..-",
	"Y": "-.--",
	"Z": "--..",
	" ": " "
}
msg = "usage: ./edramire.py <a-zA-Z string>"
argn = len(sys.argv)
if argn != 2:
	print(msg)
else:
	string = sys.argv[1]
	str_find = re.search(r'[^A-Za-z ]', string)
	if (len(string) == 0 or str_find):
		print (msg)
	else:
		string = string.upper()
		str_out = ""
		for k in string:
			str_out += morse[k]
		print(str_out)