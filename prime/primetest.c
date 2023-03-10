#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main (void)
{
    float n = get_float("number: ");

    float f = n / 2;
    int j = trunc (f);
    printf("%i.\n", j);
}
