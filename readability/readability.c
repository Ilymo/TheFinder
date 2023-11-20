#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_letters(string text);
int count_words(string text);

int main(void)
{
    //prompt user for text
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);

    printf("%i letters\n%i words\n", letters, words);

}

    //count letters
int count_letters(string text)
{
    int n_letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            n_letters++;
        }
    }
    return n_letters;
}


    //count words
int count_words(string text)
{
    int n_words = 0;

    for (int i = 0, len = strlen(text); i< len; i++)
    {
        if (isspace(text[i]) || \0)
        {
            n_words++;
        }
    }
    return n_words;
}




    //count sentences
    //print "Grade: (X)"; "Grade: 16+" if higher than 16; "Before grade 1" if lower than 1
