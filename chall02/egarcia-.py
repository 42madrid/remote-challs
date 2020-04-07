import sys

morse = {'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..',
        'J': '.---','K': '-.-', 'L': '-.--', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
        'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..'}
        
if (len(sys.argv) == 2 and all(x.isalpha()  or  x.isspace() for x in sys.argv[1])):
    for letter in sys.argv[1]:
        if letter == ' ':
            print(' ',end="")
        else :
            print(morse[letter.upper()],end="")
    print()
else:
    print('usage: ./xlogin.py <a-zA-Z string>')