#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int stock[7];

int main(void)
{
    // prompt for message
    string text = get_string("Message: ");

    //converte char to byte
    for (int i = 0, len = strlen(text); i < len; i++)
    {
       //stock binary code of the char in bit[]
       for (int n = 0; n < BITS_IN_BYTE; n++)
       {
        stock[n] = text[i] % 2;
        text[i] = text[i] / 2;
        printf("%i", text[i])
       }
       for (int x = 7; x >= 0; x--)
       {
        print_bulb(stock[x]);
       }
    printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
