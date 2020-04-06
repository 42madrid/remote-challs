#!/usr/bin/env python

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mmartin-.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 12:19:57 by mmartin-          #+#    #+#              #
#    Updated: 2020/04/06 12:19:57 by mmartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def convert_to_morse(to_encode):
	morse_map = {
		"A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".", "F": "..-.",
		"G": "--.", "H": "....", "I": "..", "J": ".---", "K": "-.-",
		"L": ".-..", "M": "--", "N": "-.", "O": "---", "P": ".--.", "Q": "--.-",
		"R": ".-.", "S": "...", "T": "-", "U": "..-", "V": "...-", "W": ".--",
		"X": "-..-", "Y": "-.--", "Z": "--..", " ": " "}
	return ''.join(map(lambda x: morse_map.get(x), to_encode))

if __name__ == "__main__":
	if len(sys.argv) != 2 or len(sys.argv[1]) < 1:
		print("usage: " + sys.argv[0] + " <a-zA-Z string>")
		exit(1)
	if not all((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or c == ' ' for c in sys.argv[1]):
		print("usage: " + sys.argv[0] + " <a-zA-Z string>")
		exit(1)
	print(convert_to_morse(sys.argv[1].upper()))
