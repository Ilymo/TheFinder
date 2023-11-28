#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

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
    int number = 0;
    int i = (strlen(input) - 1);

    while (i >= 0)
    {
    if (input[i] == '\0')
    {
        break;
    }

    number = input[i] - '0';
    printf("%i \n", number);
    input[i] = '\0';
    convert(input);
    }
    return number;



}
