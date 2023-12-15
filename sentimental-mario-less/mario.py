# TODO

from cs50 import get_int

#get height

height = get_int("height: ")

#print space
for i in range(height):
    while height > i:
        print('', end='')
        height -= 1
    print("#" * i)

