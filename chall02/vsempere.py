#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re

def printUsage():
	print('usage: ./vsempere.py <a-zA-Z string>')

def changeLetterByMorseRepresentation(letter):
	map = {'a': '.-', 'b' : '-...', 'c':'-.-.', 
	'd': '-..', 'e': '.', 'f': '..-.', 'g':'--.',
	'h': '....', 'i':'..', 'j':'.---', 'k':'-.-', 
	'l':'.-..', 'm':'--', 'n':'-.', 'o':'---', 
	'p':'.--.', 'q':'--.-', 'r':'.-.', 's':'...',
	't':'-', 'u':'..-', 'v':'...-', 'w':'.--', 
	'x':'-..-', 'y':'-.--', 'z':'--..', ' ': ' ' }
	return map[letter]

if len(sys.argv) != 2:
	print(sys.argv)
	printUsage()
	exit(1)

toTranslate = sys.argv[1]
pattern = re.compile('[^a-zA-Z\s ]')
if pattern.search(toTranslate):
	print('a')
	printUsage()
	exit(1)

translated = ''
for charToReplace in toTranslate:
	translated += changeLetterByMorseRepresentation(charToReplace.lower())
print(translated)
