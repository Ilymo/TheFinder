#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


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

    //calculate grade
    float L = (letters / words) * 100.0;
    float S = (sentences / words) * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);



    //print grade
    if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
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
        if (text[i] == '!'|| text[i] == '.' || text[i] == '?')
        {
            n_sentences++;
        }
    }
    return n_sentences;
}
