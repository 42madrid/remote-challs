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
# Solved with key-value pair dictionary as local variable in a function, due
# to local variables are faster than global variables in python.
# The achieved solution has fitted challenge's problem conception, by
# blacklisting wrong inputs by using regular expressions and, or, wrong
# invocations.
#

import sys
import re

def encrypt (message):
	morse_dict = { 'a':'.-', 'b':'-...', 'c':'-.-.', 'd':'-..', 'e':'.',
		'f':'..-.', 'g':'--.', 'h':'....', 'i':'..', 'j':'.---', 'k':'-.-',
		'l':'.-..', 'm':'--', 'n':'-.', 'o':'---', 'p':'.--.', 'q':'--.-',
		'r':'.-.', 's':'...', 't':'-', 'u':'..-', 'v':'...-', 'w':'.--',
		'x':'-..-', 'y':'-.--', 'z':'--..'}
	cipher = ''
	for char in message:
		if char >= 'a' and char <= 'z':
			cipher += morse_dict[char]
		elif  char >= 'A' and char <= 'Z':
			cipher += morse_dict[char.lower()]
		elif char == ' ':
			cipher += ' '
	return (cipher)

def main():
	if len(sys.argv) != 2 or sys.argv[1] == '' or \
		re.search(r'[^a-zA-Z ]', sys.argv[1]):
		print ('usage: ' + sys.argv[0] + ' ' + '<a-zA-Z string>')
	else:
		print (encrypt(sys.argv[1]))

if __name__ == '__main__':
	main()