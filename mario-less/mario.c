#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask for height
    int height;
    do
    {
        height = get_int("height: ");
    }
    while (8 < height < 1);
    //
}