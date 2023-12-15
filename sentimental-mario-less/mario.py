# TODO

from cs50 import get_int

#get height

height = get_int("height: ")

#print space
row = height
for i in range(height):
    print((' ' * (row - 1)), ('#' * (i + 1)))
    row -= 1





