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
    input[i] = (input[i] - '0');

    while (i >= 0)
    {
        if (input[i] == '\0')
        {
            break;
        }


        printf("%i \n", input[i]);

        number = input[i] + (number * 10);
        input[i] = '\0';

        convert(input);
    }



    return number;
}
