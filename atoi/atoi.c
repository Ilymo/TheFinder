#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
int number = 0;


int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int i = (strlen(input) - 1);
    int stock = 0;

    if (i >= 0)
    {
        stock = (input[i] - '0');
        input[i] = '\0';
        number = stock + (convert(input) * 10);
    }
    return number;
}
