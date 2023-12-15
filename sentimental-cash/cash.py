# TODO

from cs50 import get_float


def main():
    change = get_change()
    coin = int(nb_coin(change))
    print(f"{coin}")


def nb_coin(i):
    nb = 0
    #calcul quarters and remaining change
    q = i / 0.25
    nb += q
    i -= q * 0.25
    #calcul dimes
    d = i / 0.10
    nb += d
    i -= d * 0.10
    #calcul nickels
    n = i / 0.05
    nb += n
    i -= n * 0.05
    #calcul pennies
    p = i / 0.01
    nb += p

    return nb


def get_change():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            return n


main()
