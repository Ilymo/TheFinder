#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n = get_int("number: ");
    float j = n;
    float k = j / 2;


    printf("%f,%f\n",j ,k );
}