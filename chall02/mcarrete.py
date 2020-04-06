#!/usr/bin/env python

import sys

def stringToMorse(text):
	morse =		{'A' : '.-', 'B' : '-...', 'C' : '-.-.', 'D': '-..', 'E' : '.',
				'F' : '..-.', 'G' : '--.', 'H' : '....', 'I' : '..', 'J' : '.---',
				'K' : '-.-', 'L' : '.-..', 'M' : '--', 'N' :  '-.', 'O' : '---',
				'P' : '.--.', 'Q' : '--.-', 'R' : '.-.',  'S' : '...', 'T' : '-',
				'U' : '..-', 'V' : '...-', 'W' : '.--', 'X' : '-..-', 'Y' : '-.--',
				'Z' : '--..', ' ' : ' '}
	retMorse = ""
	count = 0
	error = "usage: ./mcarrete.py <a-zA-Z string>"
	for a in text:
		if a in morse:
			retMorse += morse[a]
			count += 1
		else:
			print(error)
			return error
	print(retMorse)

def main(argv):
	error = "usage: ./mcarrete.py <a-zA-Z string>"
	if len(argv) == 2 and len(argv[1]) > 0:
		stringToMorse(argv[1].upper())
	else:
		print(error)

if __name__ == '__main__':
	main(sys.argv)
