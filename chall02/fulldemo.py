#! /usr/local/bin/python3

import sys
num = len(sys.argv)
if num != 2: 
	print("usage: ./fulldemo.py <a-zA-Z string>")
	exit(1)
else:
	morse = {'a' : ".-", 'b' : "-...", 'c' : "-.-.", 'd' : "-..", 'e' : ".", 'f' : "..-.", 'g' : "--.", 'h' : "....", 'i' : "..", 'j' : ".---", 'k' : "-.-", 'l' : ".-..", 'm' : "--", 'n' : "-.", 'o' : "---", 'p' : ".--.", 'q' : "--.-", 'r' : ".-.", 's' : "...", 't' : "-", 'u' : "..-", 'v' : "...-", 'w' : ".--", 'x' : "-..-", 'y' : "-.--", 'z' : "--.."}
	res = ''
	len = len(sys.argv[1])
	if len == 0:
		print("usage: ./fulldemo.py <a-zA-Z string>")
		exit(1)
	sys.argv[1] = sys.argv[1].lower()
	count = 0
	while (count < len):
		if not sys.argv[1][count].isalpha():
			if not sys.argv[1][count].isspace():
				print("usage: ./fulldemo.py <a-zA-Z string>")
				exit(1)
		if sys.argv[1][count].isspace():
			res += sys.argv[1][count]
		else:
			res += morse[sys.argv[1][count]]
		count = count + 1
	print(res)