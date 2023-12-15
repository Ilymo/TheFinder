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
    #calcul quarters and remaining change
    q = floor(i / 0.25)
    i = Decimal(0.41) - Decimal(0.25)
    #calcul dimes
    d = floor(i / 0.10)
    i -= d * 0.10
    #calcul nickels
    n = floor(i / 0.05)
    i -= n * 0.05
    #calcul pennies
    p = floor(i / 0.01)

    nb += p + n + d + q
    return nb


def get_change():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            return n


main()
