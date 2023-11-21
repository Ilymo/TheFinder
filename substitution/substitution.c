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
}


// validate key
bool valid_key(string s);
{
    bool validation = true;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // check length
        if (len = 25)
        {
            // check only lettter
            if (isalpha(s[i]))
            {
                //check no repeated characters
                string key;
                
            }
            else
            {
                valiation = false;
            }
        }
        else
        {
            validation = false
        }
    }
    return valiation;
}



// prompt for plaintext

// encipher
    //for each character, determinate what letter it map to
    // preserve case
    // leave non-alphabetique like this
// Print ciphertext
