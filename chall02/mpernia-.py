#!/usr/bin/env python3

import sys

morse = {
	'a':'.-',
	'b':'-...',
	'c':'-.-.',
	'd':'-..',
	'e':'.',
	'f':'..-.',
	'g':'--.',
	'h':'....',
	'i':'..',
	'j':'.---',
	'k':'-.-',
	'l':'.-..',
	'm':'--',
	'n':'-.',
	'o':'---',
	'p':'.--.',
	'q':'--.-',
	'r':'.-.',
	's':'...',
	't':'-',
	'u':'..-',
	'v':'...-',
	'w':'.--',
	'x':'-..-',
	'y':'-.--',
	'z':'--..'
}

if len(sys.argv) == 2 and all(x.isalpha() or x.isspace() for x in sys.argv[1]) and len(sys.argv[1]) > 0:
	string = str.lower(sys.argv[1])
	for char in string:
		if char != ' ':
			print(morse[char], end='')
		else:
			print(' ', end='')
	print('')
else:
	print("usage: ./mpernia- <a--Z string>")
