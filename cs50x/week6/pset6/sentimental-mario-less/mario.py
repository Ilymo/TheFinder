# TODO

from cs50 import get_int


# get height
def main():
    height = get_height()
    printp(height)


# print space
def printp(n):
    row = n
    for i in range(n):
        print(" " * (row - 1), end="")
        print("#" * (i + 1))
        row -= 1


# get height from user
def get_height():
    while True:
        n = get_int("height: ")
        if n > 0 and n < 9:
            return n


main()
