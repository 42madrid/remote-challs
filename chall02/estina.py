#!/usr/bin/python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    estina.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estina <estina@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 19:21:07 by estina            #+#    #+#              #
#    Updated: 2020/04/06 19:42:57 by estina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# For arguments
import sys

# Declare our dictionaire for the MORSE
CHAR_TO_MORSE = {
	" ": " ",
	"a": ".-",
	"b": "-...",
	"c": "-.-.",
	"d": "-..",
	"e": ".",
	"f": "..-.",
	"g": "--.",
	"h": "....",
	"i": "..",
	"j": ".---",
	"k": "-.-",
	"l": ".-..",
	"m": "--",
	"n": "-.",
	"o": "---",
	"p": ".--.",
	"q": "--.-",
	"r": ".-.",
	"s": "...",
	"t": "-",
	"u": "..-",
	"v": "...-",
	"w": ".--",
	"x": "-..-",
	"y": "-.--",
	"z": "--.."
}

# Check the number of arguments and if the second argument is not empty
if len(sys.argv) != 2 or not sys.argv[1]:
	exit("usage " + sys.argv[0] + " <a-zA-Z string>")
# Declare variable for our new string
string = ""
# Passing through all of the characters
for c in sys.argv[1]:
	# Check if the character(lowered) is in our Dictionarie
	if c.lower() not in CHAR_TO_MORSE:
		exit("usage " + sys.argv[0] + " <a-zA-Z string>")
	# Add the code of the character to our new string
	string += CHAR_TO_MORSE.get(c)
# Write the new string in MORSE to the terminal
print(string)