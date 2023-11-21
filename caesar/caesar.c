#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


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
    int K = atoi(argv[1]);
    string P = get_string("Plaintext: ");
}


    //Check all argv[x] are digits (print error if not)

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
    //for each chara in plaintexte
char rotate (char c, int n)
{
    for (i = 0, len = strlen(s); i < len; i++)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
            {
                //rotate majuscule
                s[i] -= 'A'
            }
            else
            {
                //rotate minuscule
                s[i] -= 'a'
            }
        }
    }
}

        //rotate chara if it's a letter with K

    //print cyphertext
