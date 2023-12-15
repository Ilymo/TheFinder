# TODO

from cs50 import get_float


def main():
    change = get_change()
    coin = nb_coin(change)
    print(f"{coin}")


def nb_coin(i):
    nb = 0
    #calcul quarters and remaining change
    q = i / 25
    nb += q
    i -= q * 25
    #calcul dimes
    d = i / 10
    nb += d
    i -= d * 10
    #calcul nickels
    n = i / 5
    nb += n
    i -= n * 5
    #calcul pennies
    p = i /1
    nb += p
    i -= p

    return nb


def get_change():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            return n


main()
