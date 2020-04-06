# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gsanchez.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsalo <gsalo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 13:11:23 by gsanchez          #+#    #+#              #
#    Updated: 2020/04/06 13:11:51 by gsalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

MORSE_CODE = {"a": ".-",
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
        "z": "--..",
		" ": " ",}

if len(sys.argv) != 2:
	print("usage " + sys.argv[0] + " <a-zA-Z string>")
	exit()
if sys.argv[1] == "":
	print("usage " + sys.argv[0] + " <a-zA-Z string>")
	exit()
for char in sys.argv[1]:
	if char.lower() not in MORSE_CODE:
		print("usage " + sys.argv[0] + " <a-zA-Z string>")
		exit()
for char in sys.argv[1]:
	if char.lower() in MORSE_CODE:
		sys.stdout.write(MORSE_CODE[char.lower()])
	else:
		print("usage " + sys.argv[0] + " <a-zA-Z string>")
		exit()
sys.stdout.write('\n')
