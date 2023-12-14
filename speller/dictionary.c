// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Prototype for apostrophe check
bool is_apost (const char *word);

// Int size counter
int size_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * (LENGTH + 1);

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Get index of the word
    int index = hash(word);

    // Creat a cursor and take adress of the first node at this index
    node *cursor = table[index];

    // Check each node and strcmp, break if strcmp true or cursor->next == NULL
    while (cursor->next != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int index = 0;

    // use is_apost to check for apostrophe
    if (is_apost(word) == true)
    {
        index = ((toupper(word[0]) - 'A') * 46) + 45;
    }
    else
    {
        index = ((toupper(word[0]) - 'A') * 46) + (strlen(word) - 1);
    }

    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary
    FILE *dico = fopen(dictionary, "r");
    if (dico == NULL)
    {
        return false;
    }

    // for each word in dico
    char holder[LENGTH];

    // Check each word until EOF and tmp store in holder
    while(fscanf(dico, "%s", holder) != EOF)
    {
        // Creat new node
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }

        // Copy holder into the node
        strcpy(n->word, holder);
        n->next = NULL;

        // Get index for this word
        int index = hash(n->word);

        // Store the node in hash table
        n->next = table[index];
        table[index] = n;

        // increase size_count
        size_count ++;
    }


    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

bool is_apost (const char *word)
{
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if(word[i] == 39)
        {
            return true;
        }
    }
    return false;
}
