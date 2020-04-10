#! /usr/local/bin/python3

import sys

def error():
    print ("usage: " + sys.argv[0] + " <1-9 squared_rows...>")
    exit(1)

def looper(array):
	num = len(array)
	res = []
	low = 0
	high = num - 1
	count = int((num + 1) / 2) 
	for i in range(count):
		for j in range(low, high + 1):
			res += array[i][j]
		for j in range(low + 1, high + 1):
			res += array[j][high]
		for j in range(high - 1, low - 1, -1):
			res += array[high][j]
		for j in range(high - 1, low, -1):
			res += array[j][low]
		low = low + 1
		high = high - 1
	print(', '.join(res))

def checker(array):
	if len(sys.argv) < 2 or len(sys.argv) > 21:
		error()
	for i in array:
		if not i.isdigit():
			error()
		if len(i) != len(array):
			error()

def main():
	array = []
	for i in range(1, len(sys.argv)):
		array.append(sys.argv[i])
	checker(array)
	looper(array)

if __name__ == "__main__":
	main()