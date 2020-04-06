#!/usr/bin/env python
import sys
codigo_morse = {
  "A": ".-", "B": "-...", "C": "-.-.", "D": "-..", "E": ".", "F": "..-.", "G": "--.", "H": "....", "I": "..", "J": ".---", "K": "-.-", "L": ".-..", "M": "--", "N": "-.", "O": "---", "P": ".--.", "Q": "--.-", "R": ".-.", "S": "...", "T": "-", "U": "..-", "V": "...-", "W": ".--", "X": "-..-", "Y": "-.--", "Z": "--..", " ": " "
}
resultado = ""
if len(sys.argv) != 2:
  print("usage: ./szavarce.py <a-zA-Z string>")
  exit()

for c in sys.argv[1]:
  if c.upper() in codigo_morse:
    resultado += codigo_morse[c.upper()]
  else:
    print("usage: ./szavarce.py <a-zA-Z string>")
    exit()
print("{}".format(resultado))
