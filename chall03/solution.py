#!/usr/bin/env python3

import sys


def get_args():
    if len(sys.argv) < 3 or len(sys.argv) > 22:
        return None
    args = sys.argv[2:]
    if not all(len(arg) == len(args) for arg in args):
        return None
    arg_str = "".join(args)
    if not arg_str.isnumeric() or "0" in arg_str:
        return None
    return [[c for c in arg] for arg in args]


def usage():
    if len(sys.argv) < 2:
        print("usage: %s <expected_usage> <1-9 squared_rows...>" % sys.argv[0])
    print("usage: %s <1-9 squared_rows...>" % sys.argv[1])


def snail_layer(args):
    ret = args.pop(0)
    ret += [arg.pop(-1) for arg in args]
    if args:
        ret += args.pop(-1)[::-1]
    ret += [arg.pop(0) for arg in args[::-1]]
    return ret


def snail(args):
    ret = []
    while args:
        ret += snail_layer(args)
    return ret


def main():
    args = get_args()
    if not args:
        return usage()
    print(", ".join(snail(args)))


if __name__ == "__main__":
    main()
