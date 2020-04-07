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

import sys

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

if len(sys.argv) != 2 or not sys.argv[1]:
	exit("usage: " + sys.argv[0] + " <a-zA-Z string>")
string = ""
for c in sys.argv[1]:
	if c.lower() not in CHAR_TO_MORSE:
		exit("usage: " + sys.argv[0] + " <a-zA-Z string>")
	string += CHAR_TO_MORSE.get(c)
print(string)
