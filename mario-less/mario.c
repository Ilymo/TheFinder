#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask for height (1 to 8 include)
   int n;
    do
    {
        n = get_int("height: ");
    }
    while (n > 8 | n < 1);

    //print #

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        printf("#");
        printf("\n");
    }

}