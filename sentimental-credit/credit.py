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
def check_valid(n):
    #check AMEX
    if n[0] == 3:
        if n[1] in [4, 7]:
            if len(n) == 15:
                amex = luhn(n)
                if amex == 0:
                    return True
                else:
                    return False
    #check MASTER
    if n[0] == 5:
        if n[1] in [1, 2, 3, 4, 5]:
            if len(n) == 16:
                master = luhn(n)
                if master == 0:
                    return True
                else:
                    return False
    #check VISA
    if n[0] == 4:
        if len(n) == 13 or len(n) == 16:
            visa = luhn(n)
            if visa == 0:
                return True
            else:
                return False



#if valid, check if AMEX, MASTERCARD or VISA
#def check_type(n):

#Luhn's algo
def luhn(n):

main()
