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
    char key[26];
    // check length
    if (strlen(s) == 26)
    {
        //check only letter
        for (int i = 0, len = strlen(s); i < len; i++)
        {
            if (validation == true)
            {
                if (isalpha(s[i]))
                {
                    //check non repetitive characters
                    for (int n = 0, len1 = strlen(key); n < len1; n++)
                    {
                        if (validation == true)
                        {
                            if (key[n] != s[i])
                            {
                                validation = true;
                            }
                            else
                            {
                                validation = false;
                            }
                        }
                    }
                    key[i] = toupper(s[i];
                }
                else
                {
                    validation = false;
                }
            }
        }
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