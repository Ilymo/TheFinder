#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    float n = number;
    //divide "n" per 2 and stock in "k"
    float k = n / 2;

    //take result and arround the nearest and stock resulte in "j"
    int j =  trunc (k);

    //"n" - "j" stock in "r"
    //float r = k - j;

    printf("%.2f, %i\n", k, j);

    //compare "r" > 0
    if(k == j)
    {
        return false;
    }
    else
    {
        return true;
    }
}
