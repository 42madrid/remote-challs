#!/usr/bin/python3
#* ************************************************************************** */
#*                                                                            */
#*                                                        :::      ::::::::   */
#*   eligero.py                                         :+:      :+:    :+:   */
#*                                                    +:+ +:+         +:+     */
#*   By: eligero <eligero@student.42.fr>            +#+  +:+       +#+        */
#*                                                +#+#+#+#+#+   +#+           */
#*   Created: 2020/04/02 15:01:31 by eligero           #+#    #+#             */
#*   Updated: 2020/04/02 17:21:49 by eligero          ###   ########.fr       */
#*                                                                            */
#* ************************************************************************** */

#
# Constelación Serpens (Chall02) / String to Morse
#
# Solved with key-value pair dictionary. The achieved solution has the mindset
# of continuous time problem, i.e manage and output each letter at time, without
# memory allocation. In real morse each letter is transmited over radio
# connection and it can be corrupted by radio noise. I understood that every
# new command line argument means a new word, so I put a space between words.
#

import sys

MORSE_CODE_DICT = { 'A':'.-', 'B':'-...', 'C':'-.-.', 'D':'-..', 'E':'.',
					'F':'..-.', 'G':'--.', 'H':'....', 'I':'..', 'J':'.---',
					'K':'-.-', 'L':'.-..', 'M':'--', 'N':'-.', 'O':'---',
					'P':'.--.', 'Q':'--.-', 'R':'.-.', 'S':'...', 'T':'-',
					'U':'..-', 'V':'...-', 'W':'.--', 'X':'-..-', 'Y':'-.--',
					'Z':'--..'}

def encrypt(message):
	for char in message:
		if (char >= 'a' and char <= 'z') or (char >= 'A' and char <= 'Z'):
			print(MORSE_CODE_DICT[char.upper()], end = '')
		elif char == ' ':
			print(' ', end = '')
		else:
			print('#ERROR#', end = '')

def main():
	arguments = len(sys.argv) - 1
	i = 1
	while (arguments > i):
		encrypt(sys.argv[i])
		print(' ', end = '')
		i += 1
	encrypt(sys.argv[i])
	print('')

if __name__ == '__main__':
    main()