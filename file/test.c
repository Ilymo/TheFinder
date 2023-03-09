#include <stdio.h>
#include <cs50.h>

int main (void)

{
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");

    printf("Hello %s, happy to see you.\n", name);

    int n = 30;
    int delta = (30 - age);

    if (delta > 0)
    {
        printf("You are %i years from 30 years old.\n", delta);
    }
    else
    {
        printf("You are %i years over 30.\n", delta);
    }

}