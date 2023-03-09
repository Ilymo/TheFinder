#include <stdio.h>
#include <cs50.h>

int main (void)

{
    // Prompt for Name and Age
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");

    printf("Hello %s, happy to see you.\n", name);


    int delta = 40; // Age target
    int n;

// calcule the delta from age target and print the result
    if (delta > age)
    {
        n = delta - age;
        printf("You are %i years to %i years old. You'r still young :).\n", n, delta);
    }
    else
    {
        n = age - delta;
        printf("You are %i years over %i. You'r old...\n", n, delta);
    }

}