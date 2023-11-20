#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    //store Score of the current word
    int score = 0

    //compute score of each caracter
    for (int i = 0, int len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
    }








    //compte le nombre de lettre du mot = store dans length
        int length = strlen(word);
        printf("%i\n", length);

    //convertie (word) en uppercase
        int upper;
        for (int i = 0; i < length; i++)
        {
            if(isupper(word[1]))
            {
                upper = toupper(word[1]);
            }
            printf("%i\n", upper);
        }


        int n = word[1];
        printf("%i\n", n);
        return n;
}
