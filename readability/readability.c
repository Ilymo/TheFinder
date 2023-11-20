#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompt user for text
    string text = get_string("Text: ");
    //return count
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("%i letters\n%i words\n%i sentences\n", letters, words, sentences);

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

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            n_words++;
            while (isalnum(text[i]) || ispunct(text[i]))
            {
            i++;
            }
        }
    }
    return n_words;
}

    //count sentences
int count_sentences(string text)
{
    int n_sentences = 0;

    for ( int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.')
        {
            n_sentences++;
        }
    }
    return n_sentences;
}





    //print "Grade: (X)"; "Grade: 16+" if higher than 16; "Before grade 1" if lower than 1
