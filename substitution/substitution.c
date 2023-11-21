#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


bool valid_key(string s);

int main(int argc, string argv[])
{
    // get the key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!valid_key(argv[1]))
    {
        printf("Invalid key\n");
        return 1;
    }
}


// validate key
bool valid_key(string s)
{
    bool validation = true;
    // check length
    if (strlen(s) == 25)
    {
        //check only letter
        for (int i = 0, len = strlen(s); i < len; i++)
        {
            if (isalpha(s[i]))
            {
                validation = true;
            }
            else
            {
                validation = false;
            }
        }
            //check non repetitive characters
    }
    else
    {
        validation = false;
    }


    return validation;
}



// prompt for plaintext

// encipher
    //for each character, determinate what letter it map to
    // preserve case
    // leave non-alphabetique like this
// Print ciphertext
