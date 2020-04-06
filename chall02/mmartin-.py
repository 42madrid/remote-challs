#!/usr/bin/env python

import re
import sys

def convert_to_morse(to_encode):
	morse_map = {
		"A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".", "F": "..-.",
		"G": "--.", "H": "....", "I": "..", "J": ".---", "K": "-.-",
		"L": ".-..", "M": "--", "N": "-.", "O": "---", "P": ".--.", "Q": "--.-",
		"R": ".-.", "S": "...", "T": "-", "U": "..-", "V": "...-", "W": ".--",
		"X": "-..-", "Y": "-.--", "Z": "--..", " ": " "}
	return ''.join(map(lambda x: morse_map.get(x), to_encode))

if __name__ == "__main__":
	if len(sys.argv) != 2 or len(sys.argv[1]) < 1 or not all(c.isalpha() or c.isspace() for c in sys.argv[1]):
		print("usage: " + sys.argv[0] + " <a-zA-Z string>")
		exit(1)
	print(convert_to_morse(sys.argv[1].upper()))
