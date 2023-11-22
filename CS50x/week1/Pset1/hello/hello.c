#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? "); // Ask for the name
    printf("hello, %s\n", name);                    // Print the name on the screen
}