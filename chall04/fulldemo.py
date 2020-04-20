#! /usr/local/bin/python3

import sys
import fileinput

def error(e, n):
	if e == 0:
		if n != 0:
			print("%s: %s: Can't read file" % (sys.argv[0], sys.argv[n]))
		else:
			print("%s: stdin: Can't read file" % (sys.argv[0]))
	else:
		if n != 0:
			print("%s: %s: Not enough space in the given shelves" % (sys.argv[0], sys.argv[n]))
		else:
			print("%s: stdin: Not enough space in the given shelves" % (sys.argv[0]))

def shelves_to_use(all_file):
	shelves_use = 0
	for i in range(1, len(all_file)):
		line = all_file[i].split()
		if len(line) < 2:
			return (-1)
		try:
			shelves_use = int(line[0]) + shelves_use
			if int(line[0]) < 0:
				return (-1)
		except:
			return (-1)
	return(shelves_use)

def	check_to_buy(array):
	for i in range(len(array)):
		try:
			if int(array[i]) < 0:
				return (-1)
		except:
			return (-1)

def take_shelves(all_file, n):
	shelves_buy = 0
	i = 0
	shelves_use = shelves_to_use(all_file)
	array = all_file[0].split()
	if check_to_buy(array) == -1 or shelves_use == -1:
		error(0, n)
		return
	array.sort(reverse = True)
	while shelves_buy < shelves_use and i < len(array):
		try:
			shelves_buy = int(array[i]) + shelves_buy
		except:
			error(0, n)
			return
		i += 1
	if shelves_use > shelves_buy :
		error(1, n)
	else:
		print(i)

def main():
	all_file = []

	if len(sys.argv) == 1:
		all_file = sys.stdin.readlines()
		take_shelves(all_file, 0)
	else:
		for i in range(1, len(sys.argv)):
			if len(sys.argv) > 2:
				print(sys.argv[i] + ":")
			try:
				f = open(sys.argv[i], 'r')
				all_file = f.readlines()
				take_shelves(all_file, i)
				f.close()
			except:
				error(0, i)
				
if __name__ == "__main__":
	main()