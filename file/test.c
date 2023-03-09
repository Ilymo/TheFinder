#include <stdio.h>
#include <cs50.h>

int main (void)

{
    // Prompt for Name and Age
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");

    printf("Hello %s, happy to see you.\n", name);


    int delta = 30;
    int n;

    if (delta > age)
    {
        n = delta - age;
        printf("You are %i years from 30 years old.\n", n);
    }
    else
    {
        n = age - delta;
        printf("You are %i years over 30.\n", n);
    }

}