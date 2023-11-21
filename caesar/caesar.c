#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


bool only_digits(string s);


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



    //stock argv[x] in K

    //get plaintext

    //for each chara in plaintexte

        //rotate chara if it's a letter with K

    //print cyphertext
