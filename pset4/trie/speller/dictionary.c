// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
struct trie_node
{
    bool is_leaf;
    struct trie_node *children[MAX_CHILDREN_LENGTH];
};


/*
creates and initializes a new trie node
*/

trie_t trie_create(void)
{
    trie_t node = malloc(sizeof(struct trie_node));
    if (node == NULL)
    {
        return NULL;
    }

    // a new node is not a leaf node by default
    node->is_leaf = false;

    // initialize children pointers to null
    for (int i = 0; i < MAX_CHILDREN_LENGTH; i++)
    {
        node->children[i] = NULL;
    }

    return node;

}

// Hash function
unsigned int hash(const char letter)
{

    // assign the last position to the apostrophe
    if (letter == '\'')
    {
        return MAX_CHILDREN_LENGTH - 1;
    }

    // ignore case by converting the given letter to lowercase
    return tolower(letter) - 97;
}

/**
 * Inserts a new node into the trie at the right place under the key
 */

bool trie_insert(trie_t root, const char *key)
{
    trie_t node = root;

    for (int i = 0, length = strlen(key); i < length; i++)
    {
        unsigned int h = hash(key[i]);

        // create new node if necessary
        if (node->children[h] == NULL)
        {
            node->children[h] = trie_create();
        }

        node = node->children[h];

        // insufficient memory
        if (!node)
        {
            return false;
        }

    }
    node->is_leaf = true;

    return true;
}


/**
 * Searches the trie structure for the key, starting at the root node
 */

bool trie_find(trie_t root, const char *key)
{
    trie_t node = root;

    for (int i = 0, length = strlen(key); i < length; i++)
    {
        int h = hash(key[i]);

        node = node->children[h];

        if (!node)
        {
            return false;
        }
    }
    return node->is_leaf;
}

/**
 * Frees the whole tree
 */

void trie_free(trie_t root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < MAX_CHILDREN_LENGTH; i++)
    {
        trie_free(root->children[i]);
    }

    free(root);
}

trie_t root = NULL;

// Keep track of the # words in the dictionary
unsigned int words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    return trie_find(root, word);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    root = trie_create();

    if (root == NULL)
    {
        return false;
    }

    char buffer[LENGTH];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        if (!trie_insert(root, buffer))
        {
            unload();
            break;
        }
        words++;
    }
    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not loaded
unsigned int size(void)
{
    return words;
}

// Unloads the dictionary from memory, returning true if successful else false
bool unload(void)
{
    trie_free(root);

    return true;
}



