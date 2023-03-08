#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int n;
    do
    {
        n = get_int("Start Size: ");

    }
     while (n < 9);

    // TODO: Prompt for end size

    int end_size;
    do
    {
        end_size = get_int("End Size: ");

    }
     while (n  end_size);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;
    do
    {
        n = n + (n/3) - (n/4);
        years++;
    }
    while (end_size > n);

    // TODO: Print number of years

    printf("Years: %i\n", years);
}
