// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

#define MAX_CHILDREN_LENGTH 27

typedef struct trie_node *trie_t;

// Prototypes
bool load(const char *dictionary);
unsigned int size(void);
bool check(const char *word);
bool unload(void);

trie_t trie_create(void);
bool trie_insert(trie_t root, const char *key);
bool trie_find(trie_t root, const char *key);
void trie_free(trie_t root);

#endif // DICTIONARY_H
