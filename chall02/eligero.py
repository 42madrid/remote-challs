#!/usr/bin/python3
#* ************************************************************************** */
#*                                                                            */
#*                                                        :::      ::::::::   */
#*   eligero.py                                         :+:      :+:    :+:   */
#*                                                    +:+ +:+         +:+     */
#*   By: eligero <eligero@student.42.fr>            +#+  +:+       +#+        */
#*                                                +#+#+#+#+#+   +#+           */
#*   Created: 2020/04/06 14:01:31 by eligero           #+#    #+#             */
#*   Updated: 2020/04/06 15:21:49 by eligero          ###   ########.fr       */
#*                                                                            */
#* ************************************************************************** */

#
# Constelación Serpens (Chall02) / String to Morse
#
# Solved with key-value pair dictionary. The achieved solution has fits
# the challenge problem's conceivement, by blacklisting wrongs behaviors.
#

import sys

MORSE_CODE_DICT = { 'A':'.-', 'B':'-...', 'C':'-.-.', 'D':'-..', 'E':'.',
					'F':'..-.', 'G':'--.', 'H':'....', 'I':'..', 'J':'.---',
					'K':'-.-', 'L':'.-..', 'M':'--', 'N':'-.', 'O':'---',
					'P':'.--.', 'Q':'--.-', 'R':'.-.', 'S':'...', 'T':'-',
					'U':'..-', 'V':'...-', 'W':'.--', 'X':'-..-', 'Y':'-.--',
					'Z':'--..'}

def encrypt(message):
	cipher = ''
	for char in message:
		if (char >= 'a' and char <= 'z') or (char >= 'A' and char <= 'Z'):
			cipher += MORSE_CODE_DICT[char.upper()]
		elif char == ' ':
			cipher += ' '
		else:
			cipher = 'usage: ./xlogin.py <a-zA-Z string>'
			break
	return cipher if cipher != '' else 'usage: ./xlogin.py <a-zA-Z string>'

def main():
	if len(sys.argv) != 2:
		print ('usage: ./xlogin.py <a-zA-Z string>')
	else:
		print (encrypt(sys.argv[1]))

if __name__ == '__main__':
    main()