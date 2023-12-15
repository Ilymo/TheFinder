# TODO

from cs50 import get_float
from math import floor
from decimal import *
getcontext().prec = 6


def main():
    change = get_change()
    coin = int(nb_coin(change))
    print(f"{coin}")


def nb_coin(i):
    nb = 0
    i = i * 100
    #calcul quarters and remaining change
    q = i / 25
    i -= q * 25
    #calcul dimes
    d = i / 10
    i -= d * 10
    #calcul nickels
    n = i / 5
    i -= n * 5
    #calcul pennies
    p = i / 1

    nb += p + n + d + q
    return nb


def get_change():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            return n


main()
