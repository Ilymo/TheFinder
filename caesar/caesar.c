#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


bool only_digits(string s);


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

bool only_digits(string s)
    {
        if (isdigit(s[1]))
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }




    //stock argv[x] in K

    //get plaintext

    //for each chara in plaintexte

        //rotate chara if it's a letter with K

    //print cyphertext
