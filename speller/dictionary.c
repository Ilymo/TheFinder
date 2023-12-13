// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
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
    do
    {
        //read word and store in holder
        fscanf(dico, "%s", holder);

        //creat new node
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }

        //copy holder into the node
        strcpy(n->word, holder);
        n->next = NULL;

        //get index for this word
        int index = hash(n->word);

        //store the node in hash table
        n->next = table[index];
        table[index] = n;
    }
    while(fscanf(dico, "%s", holder) != EOF);



    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
