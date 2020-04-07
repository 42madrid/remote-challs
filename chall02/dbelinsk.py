#!/usr/bin/env python3
import sys

def encode(c):
	if c is 'a':
		return ".-"
	elif c is 'b':
		return "-..."
	elif c is 'c':
		return "-.-."
	elif c is 'd':
		return "-.."
	elif c is 'e':
		return "."
	elif c is 'f':
		return "..-."
	elif c is 'g':
		return "--."
	elif c is 'h':
		return "...."
	elif c is 'i':
		return ".."
	elif c is 'j':
		return ".---"
	elif c is 'k':
		return "-.-"
	elif c is 'l':
		return ".-.."
	elif c is 'm':
		return "--"
	elif c is 'n':
		return "-."
	elif c is 'o':
		return "---"
	elif c is 'p':
		return ".--."
	elif c is 'q':
		return "--.-"
	elif c is 'r':
		return ".-."
	elif c is 's':
		return "..."
	elif c is 't':
		return "-"
	elif c is 'u':
		return "..-"
	elif c is 'v':
		return "...-"
	elif c is 'w':
		return ".--"
	elif c is 'x':
		return "-..-"
	elif c is 'y':
		return "-.--"
	elif c is 'z':
		return "--.."
	elif c is ' ':
		return " "

def morseLoop(s):
	code = ''
	for c in s:
		code += encode(c)
	print (code)

def is_all_letter(av):
	i = 0
	for c in av:
		i += 1
		if c.isalpha() == False:
			if c != ' ':
				return 0
	if i == 0:
		return 0
	return 1

def warning(s):
	print ('usage:', s, '<a-zA-Z string>')

if __name__ == "__main__":
	ac = len(sys.argv)
	fname = sys.argv[0]
	if ac == 2:
		av = sys.argv[1].lower()
		if is_all_letter(av) == 1:
			morseLoop(av)
		else:
			warning(fname)
	else:
		warning(fname)
