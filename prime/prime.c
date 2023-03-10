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
    //divide "i" per 2 and stock in "n"
    float n = number / 2;
    //take result and arround the nearest and stock resulte in "j"
    float j = trunc (n);
    //"n" - "j" stock in "r"
    float r = n - j;
    //compare "r" > 0
    if(r > 0)
    {
        return true;
    }
}
