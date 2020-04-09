#!/usr/bin/python
import sys
import numpy as np

TRACE = False

def get_argv_list(argv):
    argv_row = []
    while argv:
        argv_row.append(argv[:1])
        argv = argv[1:]
    if TRACE:
        print(argv_row)
    return argv_row

def create_squared_rows(list_argv):
    alist = []
    matrix_list = []
    for argv in list_argv:
        alist = get_argv_list(argv)
        matrix_list.append(alist)
    squared_rows = np.array(matrix_list)
    if TRACE:
        print("\nInput Matrix ", squared_rows.shape)
        print(squared_rows)
        print("")
    return squared_rows

def check_argv(list_argv):
    num_argv = 0
    len_ref_argv = len(list_argv[0])
    if len(list_argv) != len_ref_argv:
        return False
    for argv in list_argv:
        num_argv += 1 
        len_argv = len(argv)
        if TRACE:
            print("Argv[%d]: %s, len=%d", (num_argv, argv, len_argv)) 
        if not argv.isdigit() or len_argv != len_ref_argv:
            return False
    return True

def get_snail_str(snail_result):
    argv_row = []
    while snail_result:
        argv_row.append(snail_result[:1])
        snail_result = snail_result[1:]
    snail_str = ", ".join(argv_row)
    if TRACE:
        print(snail_str)
    return(snail_str)

def snail (row_init, row_end, col_init, col_end, squared_rows):
    snail_result =''
    if row_init == row_end and col_init == col_end:
        snail_result = squared_rows[row_init,col_init] 
    for row in range (row_init, row_end, 1):
        if row == row_init:
            for col in range(col_init, col_end):
                snail_result += str(squared_rows[row, col])
        elif row == (row_end - 1):
            for col in reversed(range(col_init, col_end)):
                snail_result += str(squared_rows[row, col])
        else:
             snail_result += squared_rows[row,col_end-1]
    for row in reversed(range (row_init + 1, row_end - 1)):
        snail_result += squared_rows[row, col_init]
    snail_str = get_snail_str(snail_result)
    if TRACE:
        print(snail_str)       
    return snail_str

if __name__ == "__main__":
    if len(sys.argv) < 2 or not check_argv(sys.argv[1:]):
        print ("usage: ./mpena-gu.py <1-9 squared_rows...>")
        sys.exit()
    squared = create_squared_rows(sys.argv[1:])
    num_squared = squared.shape[0]//2 
    if squared.shape[0]%2 != 0:
        num_squared += 1
    i = 0 
    snail_result = "" 
    while i< num_squared:
        if i>0:
            snail_result += ', '
        row_init = i
        row_end  = squared.shape[0]-i
        col_init = i
        col_end  = squared.shape[1]-i
        snail_result += snail(row_init,row_end,col_init,col_end, squared)
        i += 1
    print(snail_result)
