#!/usr/bin/env python3

import sys

code = {
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
    "z": "--..",
    " ": " ",
}


def get_arg():
    if len(sys.argv) != 3:
        return None
    return sys.argv[2] if sys.argv[2].replace(" ", "").isalpha() else None


def usage():
    if len(sys.argv) <= 2:
        return print("usage: %s <login> <a-A-Z string>" % sys.argv[0])
    return print("usage: ./%s.py <a-zA-Z string>" % sys.argv[1])


def main():
    arg = get_arg()
    if arg is None:
        return usage()
    print("".join(code[c] for c in arg.lower()))


if __name__ == "__main__":
    main()
