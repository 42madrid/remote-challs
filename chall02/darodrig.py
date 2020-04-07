#!/usr/bin/python
import sys

def main():
	chars = { 'A':'.-', 'B':'-...', 
                    'C':'-.-.', 'D':'-..', 'E':'.', 
                    'F':'..-.', 'G':'--.', 'H':'....', 
                    'I':'..', 'J':'.---', 'K':'-.-', 
                    'L':'.-..', 'M':'--', 'N':'-.', 
                    'O':'---', 'P':'.--.', 'Q':'--.-', 
                    'R':'.-.', 'S':'...', 'T':'-', 
                    'U':'..-', 'V':'...-', 'W':'.--', 
                    'X':'-..-', 'Y':'-.--', 'Z':'--..'}
	if len(sys.argv) != 2 or sys.argv[1] == "":
		print("usage: ./xlogin.py <a-zA-Z string>")
		return
	for each in sys.argv[1]:
		if each.isalpha() == 0 and each != ' ':
			print("usage: ./xlogin.py <a-zA-Z string>")
			return
	for each in sys.argv[1]:
		if each == ' ':
			sys.stdout.write(each)
		else:
			sys.stdout.write(chars[each.upper()])
	sys.stdout.write('\n')
	return

if __name__ == "__main__":
	main()
