#!/usr/bin/python3
import sys

def errorCode():
    print("usage: ./xlogin.py <a-zA-Z string>")
    quit()

if((len(sys.argv) > 2) or (len(sys.argv) == 1)):
    errorCode()
if(len(sys.argv[1]) == 0):
    errorCode()
morse = ""
for c in sys.argv[1].lower():
    if(not(c.isalpha()) and not(c.isspace())):
        errorCode()
    if (c == 'a'):
        morse += '.-'
    elif (c == 'b'):
        morse += '-...'
    elif (c == 'b'):
        morse += '-...'
    elif (c == 'c'):
        morse += '-.-.'
    elif (c == 'd'):
        morse += '-..'
    elif (c == 'e'):
        morse += '.'
    elif (c == 'f'):
        morse += '..-.'
    elif (c == 'g'):
        morse += '--.'
    elif (c == 'h'):
        morse += '....'
    elif (c == 'i'):
        morse += '..'
    elif (c == 'j'):
        morse += '.---'
    elif (c == 'k'):
        morse += '.-.'
    elif (c == 'l'):
        morse += '.-..'
    elif (c == 'm'):
        morse += '--'
    elif (c == 'n'):
        morse += '-.'
    elif (c == 'o'):
        morse += '---'
    elif (c == 'p'):
        morse += '.--.'
    elif (c == 'q'):
        morse += '--.-'
    elif (c == 'r'):
        morse += '.-.'
    elif (c == 's'):
        morse += '...'
    elif (c == 't'):
        morse += '-'
    elif (c == 'u'):
        morse += '..-'
    elif (c == 'v'):
        morse += '...-'
    elif (c == 'w'):
        morse += '.--'
    elif (c == 'x'):
        morse += '-..-'
    elif (c == 'y'):
        morse += '-.--'
    elif (c == 'z'):
        morse += '--..'
    elif (c == ' '):
        morse += ' '
print(morse)
