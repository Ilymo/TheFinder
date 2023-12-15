# TODO

from cs50 import get_float
from math import floor


def main():
    change = get_change()
    coin = int(nb_coin(change))
    print(f"{coin}")


def nb_coin(i):
    nb = 0
    i = i * 100
    #calcul quarters and remaining change
    q = floor(i / 25)
    i -= q * 25
    #calcul dimes
    d = floor(i / 10)
    i -= d * 10
    #calcul nickels
    n = floor(i / 5)
    i -= n * 5
    #calcul pennies
    p = floor(i / 1)

    nb += p + n + d + q
    return nb


def get_change():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            return n


main()
