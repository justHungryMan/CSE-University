#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define TABLE_INIT_SIZE 8

typedef struct chaining {
  char *value;
  char *key;
  struct chaining *next;
} chaining;

typedef struct hashTable {
  struct chaining **data;
  int capacity;
  int size;
} jHashTable;

// Creates a new hash table with size slots.
jHashTable *jHashTableNew(int capacity);
// Table doubling when changed size.
void jHashTableDoubling(jHashTable *hashTable);
// Frees memory associated with given hash table.
void jHashTableDestroy(jHashTable *hashTable);
// Free data
void jHashTableDestroyData(jHashTable *hashTable);
// Universal string hashing algorithm
int hash(const char* key, const int m);
// Add the given key and value to chaing
chaining *jHashTableAddChain(const char* key, const char* value);
// Add the given key and object to hash table. If key exists, make chain.
void jHashTableAdd(char *key, char* value, jHashTable *hashTable);
// Returns true if the given key exists in the table
bool jHashTableExists(const char *key, jHashTable *hashTable);
// Return value by key, if not return NULL.
char *jHashTableGet(const char *key, jHashTable *hashTable);
// Remove data by key.
void jHashTableRemove(const char *key, jHashTable *hashTable);
// Show Table
void showHashTable(jHashTable *hashTable);
