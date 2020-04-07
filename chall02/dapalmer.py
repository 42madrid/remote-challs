#!/usr/bin/python

import sys

def main():
    if len(sys.argv) == 2:
        morseCode = {
            'A': '.-',
            'B': '-...',
            'C': '-.-.',
            'D': '-..',
            'E': '.',
            'F': '..-.',   
            'G': '--.',
            'H': '....',
            'I': '..',   
            'J': '.---',
            'K': '-.-',
            'L': '.-..',   
            'M': '--',
            'N': '-.',
            'O': '---',   
            'P': '.--.',
            'Q': '--.-',
            'R': '.-.',
            'S': '...',
            'T': '-',
            'U': '..-',
            'V': '...-',
            'W': '.--',
            'X': '-..-',
            'Y': '-.--',
            'Z': '--..',
            ' ': ' '       
        }
        origString = sys.argv[1].upper()
        morseString = ''

        for char in origString:
            if char >= 'A' and char <= 'Z' or char == ' ':
                morseString += morseCode[char]
        print morseString
    
    else:
        print 'Usage:', sys.argv[0], '<a-zA-Z>'

if __name__ == "__main__":
    main()

