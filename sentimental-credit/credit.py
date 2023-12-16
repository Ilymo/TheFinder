# TODO
from cs50 import get_int



def main():
    number = get_card_nb()
    print(number)






#prompt for credit card nb and check length
def get_card_nb():
    while True:
        n = input("number: ")
        if len(n) in [15, 16, 13]:
            return n





#check if valid
#def check_valid(n):


#if valid, check if AMEX, MASTERCARD or VISA
#def check_type(n):

main()
