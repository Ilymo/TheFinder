#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool test(char c);

int main(void)
{
    char letter = get_char("char: \n");
    if (test(letter))
    {
        printf("%c is a letter", letter);
    }
    else
    {
        printf("%c is not a letter", letter);
    }
}

bool test(char c)
{
    if (isalpha(c))
    {
        return true;
    }
    else
    {
        return false;
    }
}
