#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure getting 1 argument (not 0 else 2+: return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert argv to int K
    int K = atoi(argv[1]);

    // prompt for plaintext
    string P = get_string("plaintext: ");

    // print "cyphertext"
    printf("ciphertext: ");

    // print rotate char
    for (int i = 0, len = strlen(P); i < len; i++)
    {
        printf("%c", rotate(P[i], K));
    }
    printf("\n");
}

// Check all argv[x] are digits (print error if not)

bool only_digits(string s)
{
    bool answer = true;
    {
        for (int i = 0, len = strlen(s); i < len; i++)
        {
            if (answer == true)
            {
                if (isdigit(s[i]))
                {
                    answer = true;
                }
                else
                {
                    answer = false;
                }
            }
        }
    }
    return answer;
}
// for each chara in plaintexte
char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            // rotate majuscule
            c -= 'A';
            c = (c + n) % 26;
            c += 'A';
        }
        else
        {
            // rotate minuscule
            c -= 'a';
            c = (c + n) % 26;
            c += 'a';
        }
    }
    return c;
}