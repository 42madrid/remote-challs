import sys

dictionary = [ '.-', '-...', '-.-.', '-..', '.', '..-.', '--.', '....',
            '..', '.---', '-.-', '.-..', '--', '-.', '---', '.--.',
            '--.-', '.-.', '...', '-', '..-', '...-', '.--', '-..-',
            '-.--', '--..']

def error():
    print("usage: ./" + sys.argv[0] + " <a-zA-Z string>")

def morse(string):
    code = ''
    for letter in string:
        if letter.isalpha():
                code += dictionary[ord(letter) - 97]
        elif letter == ' ':
                code += ' '
        else:
            error()
            exit(1)
    return code

if len(sys.argv) == 2 and len(sys.argv[1]) > 0:
    print (morse(sys.argv[1].lower()))
else:
    error()
