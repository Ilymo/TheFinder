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

    int i = 0;
    while (i < n)
    {
        for ( int j = 0; j < n; j--)
        {
            printf("#");
        }
       printf("\n");
        i++;
    }

}