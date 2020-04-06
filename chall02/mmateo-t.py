# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    chall-02.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguel <miguel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 16:23:52 by miguel            #+#    #+#              #
#    Updated: 2020/04/06 19:29:28 by miguel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

error = False
spaces = 0
morse = {
'a' :'.-',
'b' : '-...', 
'c' : '-.-.', 
'd' : '-..', 
'e' : '.' ,
'f' : '..-.', 
'g' :'--.' ,
'h' :'....' ,
'i' :'..' ,
'j' : '.---', 
'k' :'-.-' ,
'l' :'.-..' ,
'm' :'--' ,
'n' :'-.' ,
'o' :'---' ,
'p' :'.--.' ,
'q' :'--.-' ,
'r' :'.-.',
's' :'...' ,
't' :'-',
'u' :'..-' ,
'v' :'...-' ,
'w' :'.--' ,
'x' :'-..-' ,
'y' :'-.--' ,
'z' : '--..',
' ' : ' '
}

if len(sys.argv) != 2 or not sys.argv[1]:
	print("usage: ./mmateo-t.py <a-zA-Z string>")
else:
	string = sys.argv[1].lower()
	for c in string:
		if c not in morse:
			error = True
			break
		if c == ' ':
			spaces+=1

	if not error and spaces < len(string):
		for c in string:
			print(morse.get(c), end="")
		print("")
	else:
		print("usage: ./mmateo-t.py <a-zA-Z string>")

sys.exit()
