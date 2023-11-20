#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int BYTE[];

int main(void)
{
    // prompt for message
    string text = get_string("Message: ");

    //converte char to byte
    for (int i = 0, len = strlen(text); i < len; i++)
    {
       BYTE[i] = text[i] % 2;
       printf("%i \n",BYTE[i]);
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
