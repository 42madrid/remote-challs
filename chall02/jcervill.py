import sys

i = 0
morse = {
	'a':'.-',
	'A':'.-',
	'b':'-...',
	'B':'-...',
	'c':'-.-.',
	'C':'-.-.',
	'd':'-..',
	'D':'-..',
	'e':'.',
	'E':'.',
	'f':'..-.',
	'F':'..-.',
	'g':'--.',
	'G':'--.',
	'h':'....',
	'H':'....',
	'i':'..',
	'I':'..',
	'j':'.---',
	'J':'.---',
	'k':'-.-',
	'K':'-.-',
	'l':'.-..',
	'L':'.-..',
	'm':'--',
	'M':'--',
	'n':'-.',
	'N':'-.',
	'o':'---',
	'O':'---',
	'p':'.--.',
	'P':'.--.',
	'q':'--.-',
	'Q':'--.-',
	'r':'.-.',
	'R':'.-.',
	's':'...',
	'S':'...',
	't':'-',
	'T':'-',
	'u':'..-',
	'U':'..-',
	'v':'...-',
	'V':'...-',
	'w':'.--',
	'W':'.--',
	'x':'-..-',
	'X':'-..-',
	'y':'-.--',
	'Y':'-.--',
	'z':'--..',
	'Z':'--..',
	' ':' '
}

def error():
	print("usage: " + sys.argv[0] + " <a-zA-Z string>")
	exit(1)

def is_morse(dictionary, strin):
	for j in strin:
		if not (j.isspace() or j.isalpha()):
			error()
		if not(dictionary[j]):
			error()
	return 1

if (len(sys.argv) == 2 and len(sys.argv[1]) > 0):
	if (is_morse(morse, sys.argv[1]) == 1):
		str = ""
		while (i < len(sys.argv[1])):
			str = str + (morse[sys.argv[1][i]])
			i += 1
		print (str)
	else:
		error()
else:
	error()
