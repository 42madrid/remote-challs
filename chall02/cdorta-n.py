#/usr/bin/python3
# -*- coding: utf-8 -*-

import sys

num = len(sys.argv)

if num != 2:
        print("usage: ./cdorta-n.py <a-zA-Z string>")
        exit(0)
else:
    codigo_morse = {
        "a": ".-", "b": "-...", "c": "-.-.", "d": "-..", "e": ".", "f": "..-.", 
        "g": "--.", "h": "....", "i": "..", "j": "·---", "k": "-.-", "l": ".-..", 
        "m": "--", "n": "-.", "ñ": "--.--", "o": "---", "p": ".__.", "q": "--.-",
        "r": ".-.", "s": "...", "t": "-", "u": "..-", "v": "...-", "w": ".--",
        "x": "-..-", "y": "-.--", "z": "--..",
        
        "0": "-----", "1": ".----", "2": "..---", "3": "...--", "4": "....-", 
        "5": ".....", "6": "-....", "7": "--...", "8": "---..", "9": "----.",
        
        ".": ".-.-.-", ",": "-.-.--", "?": "..--..", "\"": ".-..-."
    }
    texto_codificado = ''

    len = len(sys.argv[1])
    sys.argv[1] = sys.argv[1].lower()
    contador = 0

    while (contador < len):
        if not sys.argv[1][contador].isalpha():
            if not sys.argv[1][contador].isspace():
                print("usage: ./cdorta-n.py <a-zA-Z string>")
                exit(0)
        if sys.argv[1][contador] != " ":
            texto_codificado += codigo_morse[sys.argv[1][contador]]
        else:
            texto_codificado += sys.argv[1][contador]
        contador += 1
    print(texto_codificado)