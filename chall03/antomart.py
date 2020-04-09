#!/usr/bin/env python3

import sys
import re

def main():
    n_args = len(sys.argv)
    args_val = sys.argv
    args_val.remove(sys.argv[0])
    pattern = re.compile("[1-9]+")
    j = 0
    if (n_args == 1):
        print("usage: ./antomart.py <1-9 squared_rows...>")
    else:
        if (n_args == 2 and len(sys.argv[0]) == 1 ):
            if (pattern.fullmatch(sys.argv[0]) is  None):
                print("usage: ./antomart.py <1-9 squared_rows...>")
            else:
                print(sys.argv[0])
        else:
            for k in range(1, n_args -1):
                if (pattern.fullmatch(sys.argv[k]) is  None and j == 0):
                    print("usage: ./antomart.py <1-9 squared_rows...>")
                    j = 1
                else:
                    args_len = [len(str) for str in sys.argv]
                    args_len.remove(args_len[0])
            if (j == 1):
                return
            if (n_args != 2 and all(int == args_len[0] for int in args_len) and n_args - 1 == args_len[0] and args_len[0] >= 1 and args_len[0] <= 20):
                        
                        lenght = len(sys.argv[1])
                        i = 0
                        r = 1
                        rmax = n_args - 1
                        imax = lenght
                        rmin = 0
                        imin = 0
                        iteration = (lenght * 2) - 1
                        snail = []
                        while (iteration > 0):
                            if (iteration > 0):
                                while(i < imax):
                                    snail.append(sys.argv[rmin][i])
                                    i = i + 1
                                i = i - 1
                               
                                imax = imax - 1
                                iteration = iteration -1
                            
                            if (iteration > 0):
                                while (r < rmax):
                                    snail.append(sys.argv[r][imax])
                                    r = r + 1
                                r = r - 1
                                i = i - 1
                                rmax = rmax - 1
                                iteration = iteration - 1
                                
                            if (iteration > 0):
                                while (i >= imin):
                                    snail.append(sys.argv[rmax][i])
                                    i = i - 1
                                i = i + 1
                                r = r - 1
                                iteration = iteration - 1
                                
                                
                            if (iteration > 0):
                                while (r > rmin):
                                    snail.append(sys.argv[r][imin])
                                    r = r - 1
                                r = r + 1
                                i = i + 1
                                iteration = iteration - 1
                                rmin = rmin + 1
                        print(snail)
                                
                            

            else:
                print("usage: ./antomart.py <1-9 squared_rows...>")

if __name__ == "__main__":
    main()