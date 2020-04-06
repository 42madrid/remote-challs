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
# Solved with key-value pair dictionary as static variable in a class.
# The achieved solution has fitted challenge's problem conception, by
# blacklisting wrong inputs by using regular expressions and, or, wrong
# invocations. Memory clean.
#

import sys
import re

class morse:
	dictionary = { 'a':'.-', 'b':'-...', 'c':'-.-.', 'd':'-..', 'e':'.',
		'f':'..-.', 'g':'--.', 'h':'....', 'i':'..', 'j':'.---', 'k':'-.-',
		'l':'.-..', 'm':'--', 'n':'-.', 'o':'---', 'p':'.--.', 'q':'--.-',
		'r':'.-.', 's':'...', 't':'-', 'u':'..-', 'v':'...-', 'w':'.--',
		'x':'-..-', 'y':'-.--', 'z':'--..'}

	def encrypt (self, message):
		cipher = ''
		for char in message:
			if char >= 'a' and char <= 'z':
				cipher += self.dictionary[char]
			elif  char >= 'A' and char <= 'Z':
				cipher += self.dictionary[char.lower()]
			elif char == ' ':
				cipher += ' '
		return (cipher)

	def __init__ (self, message):
		self.message = message
		self.encrypted = self.encrypt(message)

def main():
	if len(sys.argv) != 2 or sys.argv[1] == '' or \
		re.search(r'[^a-zA-Z ]', sys.argv[1]):
		print ('usage: ' + sys.argv[0] + ' ' + '<a-zA-Z string>')
	else:
		user_input = morse(sys.argv[1])
		print (user_input.encrypted)
		del user_input

if __name__ == '__main__':
    main()