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
    //convert to float
    float n = number;
    int m = number;
    
    //divide par each number from i to n-1
    for (float i = 2;n > m ;i++)
    {
       float j = n / i;
       float k = number / i;
    }
    return false
}





