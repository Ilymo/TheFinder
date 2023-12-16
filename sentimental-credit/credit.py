# TODO
from cs50 import get_int



def main():
    number = get_card_nb()
    result = check_valid(number)
    print(result)


#prompt for credit card nb and check length
def get_card_nb():
    while True:
        n = input("number: ")
        if len(n) in [15, 16, 13]:
            return n


#check if valid, if yes return the type
def check_valid(n):
    #check AMEX
    if n[0] == '3':
        if n[1] in [4, 7]:
            if len(n) == 15:
                amex = luhn(n)
                if amex == 0:
                    return 'AMEX'
                else:
                    return 'INVALID'
    #check MASTER
    elif n[0] == 5:
        if n[1] in range(1, 5):
            if len(n) == 16:
                master = luhn(n)
                if master == 0:
                    return 'MASTERCARD'
                else:
                    return 'INVALID'
    #check VISA
    elif n[0] == 4:
        if len(n) == 13 or len(n) == 16:
            visa = luhn(n)
            if visa == 0:
                return 'VISA'
            else:
                return 'INVALID'
    else:
        return 'INVALID'


#Luhn's algo
def luhn(n):
    sum = 0
    length = len(n)
    holder = 0

    #add 0,2,4... to sum
    for i in range(0, length, 2):
        holder = int(n[i]) * 2
        holder = str(holder)
        for k in range(len(holder)):
            sum += int(holder[k])

    #multi other by 2 and add to sum
    for j in range(1, length, 2):
        sum += int(n[j])
        j += 2

    #return last digit
    return(sum % 10)


main()
