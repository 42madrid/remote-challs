#!/usr/bin/env python3
# String to Morse: Display <a-zA-Z string> as morse code
import sys

morse_dictionary =    {'a' : ".-", 'b' : "-...", 'c' : "-.-.", 'd' : "-..", \
                        'e' : ".", 'f' : "..-.", 'g' : "--.", 'h' : "....", \
                        'i' : "..", 'j' : ".---", 'k' : "-.-", 'l' : ".-..", \
                        'm' : "--", 'n' : "-.", 'o' : "---", 'p' : ".--.", \
                        'q' : "--.-", 'r' : ".-.", 's' : "...", 't' : "-", \
                        'u' : "..-", 'v' : "...-", 'w' : ".--", 'x' : "-..-", \
                        'y' : "-.--", 'z' : "--.."}

# Converts string to morse using morse_dictionary as reference and prints it
def print_morse(string):
    morse = ''
    string = string.lower()
    for letter in string:
        if letter.isspace():
            morse += letter
        else:
            morse += morse_dictionary[letter]
    print(f'{morse}')

# Check if parameter consist only of lowercase, uppercase or space characters
def check_string(string):
    for letter in string:
        if letter.islower() or letter.isupper() or letter.isspace():
            continue
        else:
            return False
    return True

# Check if there is only one argument, argument is not empty and contains only letters or space
def check_errors():
    if len(sys.argv) != 2 or not sys.argv[1] or not check_string(sys.argv[1]):
        sys.exit(f'usage: {sys.argv[0]} <a-zA-Z string>')

# Check for errors then print first command line argument as morse code
def main():
    check_errors()
    print_morse(sys.argv[1])
    sys.exit(0)

# Execute the main function
if __name__ == '__main__':
    main()
