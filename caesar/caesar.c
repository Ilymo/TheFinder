#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int only_digits(string s);


int main(int argc, string argv[])
{
    // Make sure getting 1 argument (not 0 else 2+: return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


    //Check all argv[x] are digits (print error if not)

int only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isdigit(s[i]))
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return 2;

}



    //stock argv[x] in K

    //get plaintext

    //for each chara in plaintexte

        //rotate chara if it's a letter with K

    //print cyphertext
