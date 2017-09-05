#include "hashTable.h"

// Creates a new hash table with size slots.
jHashTable **jHashTableNew(int capacity) {
  jHashTable **hashTablePointer = (jHashTable **)malloc(sizeof(jHashTable *));
  *hashTablePointer = jHashTableCreate(capacity);
  return hashTablePointer;
}

jHashTable *jHashTableCreate(int capacity) {
  jHashTable *hashTable = (jHashTable *)malloc(sizeof(jHashTable));
  hashTable->size = 0;
  hashTable->capacity = capacity;
  hashTable->data = (chaining **)malloc(sizeof(chaining*) * capacity);
  for (int i = 0; i < capacity; ++i) {
    hashTable->data[i] = NULL;
  }
  return hashTable;
}
// Table doubling when changed size.
void jHashTableDoubling(jHashTable **hashTable) {
  bool isDoubleing = false;
  int doublingSize = TABLE_INIT_SIZE;
  if ((*hashTable)->size == (*hashTable)->capacity) {
      isDoubleing = true;
      doublingSize = (*hashTable)->capacity * 2;
  }
  else if ((*hashTable)->size == (*hashTable)->capacity / 4 && (*hashTable)->capacity >= 32) {
      isDoubleing = true;
      doublingSize = (*hashTable)->capacity / 4;
  }
  if (isDoubleing) {
    jHashTable *newHashTable = jHashTableCreate(doublingSize);
    for (int i = 0; i < (*hashTable)->capacity; ++i) {
        for (chaining *traversal = (*hashTable)->data[i]; traversal != NULL; traversal = traversal->next) {
            int hashedKey = hash(traversal->key, newHashTable->capacity);
            if (newHashTable->data[hashedKey] == NULL) {
              newHashTable->data[hashedKey] = jHashTableAddChain(traversal->key, traversal->value);
              newHashTable->size += 1;
            }
            else {
              chaining *newChain = jHashTableAddChain(traversal->key, traversal->value);
              newChain->next = newHashTable->data[hashedKey]->next;
              newHashTable->data[hashedKey]->next= newChain;
              newHashTable->size += 1;
            }
        }
    }
    jHashTableDestroyData(hashTable);
    *hashTable = newHashTable;
  }
}
// Frees memory associated with given hash table.
void jHashTableDestroy(jHashTable **hashTable) {
  jHashTableDestroyData(hashTable);
  free(hashTable);
}
// Free data
void jHashTableDestroyData(jHashTable **hashTable) {
  for (int i = 0; i < (*hashTable)->capacity; ++i) {
    chaining* traversal = (*hashTable)->data[i];
    while (traversal != NULL) {
      chaining* destoriedChain = traversal;
      traversal = traversal->next;
      free(destoriedChain->key);
      free(destoriedChain->value);
      free(destoriedChain);
    }
  }
  free((*hashTable)->data);
  free(*hashTable);
}
// Universal string hashing algorithm
int hash(const char* key, const int m) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        hash = hash * 31 + key[i];
    }
    return abs(hash % m);
}
// Add the given key and value to chaing
chaining *jHashTableAddChain(const char* key, const char* value) {
    int valueLen = (int)strlen(value);
    int keyLen = (int)strlen(key);
    chaining *newChain = (chaining *)malloc(sizeof(chaining));
    newChain->value = (char *)malloc(sizeof(char) * (valueLen + 1));
    newChain->key = (char *)malloc(sizeof(char) * (keyLen + 1));
    newChain->next = NULL;
    strncpy(newChain->value, value, valueLen + 1);
    strncpy(newChain->key, key, valueLen + 1);
    return newChain;
}
// Add the given key and object to hash table. If key exists, make chain.
void jHashTableAdd(char *key, char *value, jHashTable **hashTable) {
    int hashedKey = hash(key, (*hashTable)->capacity);
    bool isKeyExist = false;
    chaining *findLastChain = (*hashTable)->data[hashedKey];
    if (findLastChain == NULL) {
        (*hashTable)->data[hashedKey] = jHashTableAddChain(key, value); // 여기가 문제! find last chain -> next로 할당 해야 할 것 같음.
        (*hashTable)->size += 1;
        jHashTableDoubling(hashTable);
    }
    else {
        for (findLastChain = (*hashTable)->data[hashedKey]; findLastChain->next != NULL; findLastChain = findLastChain->next) {
            if (!strcmp(findLastChain->key, key)) {
                strncpy(findLastChain->value, value, strlen(value) + 1);
                isKeyExist = true;
                break;
            }
        }
        if (isKeyExist == false) {
            findLastChain->next = jHashTableAddChain(key, value);
            //findLastChain = findLastChain->next;
            (*hashTable)->size += 1;
            jHashTableDoubling(hashTable);
        }
    }
}
// Returns true if the given key exists in the table
bool jHashTableExists(const char *key, jHashTable **hashTable) {
    int hashedKey = hash(key, (*hashTable)->capacity);
    for (chaining *traversal = (*hashTable)->data[hashedKey]; traversal != NULL; traversal = traversal->next) {
        if (!strcmp(traversal->key, key)) return true;
    }
    return false;
}
// Return value by key, if not return NULL.
char *jHashTableGet(const char *key, jHashTable **hashTable) {
    int hashedKey = hash(key, (*hashTable)->capacity);
    for (chaining *traversal = (*hashTable)->data[hashedKey]; traversal != NULL; traversal = traversal->next) {
        if (!strcmp(traversal->key, key)) return traversal->value;
    }
    return "NULL";
}
// Remove data by key.
void jHashTableRemove(const char *key, jHashTable **hashTable) {
    int hashedKey = hash(key, (*hashTable)->capacity);
    if (!strcmp((*hashTable)->data[hashedKey]->key, key)) {
      chaining *destoriedChain = (*hashTable)->data[hashedKey];
      free(destoriedChain->key);
      free(destoriedChain->value);
      (*hashTable)->data[hashedKey] = destoriedChain->next;
      free(destoriedChain);
    }
    else {
        chaining *traversal, *prev;
        for (prev = (*hashTable)->data[hashedKey], traversal = (*hashTable)->data[hashedKey]->next; strcmp(traversal->key, key); prev = prev->next, traversal = traversal->next);
        free(traversal->key);
        free(traversal->value);
        prev->next = traversal->next;
        free(traversal);
    }
    (*hashTable)->size -= 1;
    jHashTableDoubling(hashTable);
}
// Show Table
void showHashTable(jHashTable **hashTable) {
    printf("===\nshow Table\n\n");
    for (int i = 0; i < (*hashTable)->capacity; ++i) {
        printf("===   index : %d\n", i);
        for (chaining *traversal = (*hashTable)->data[i]; traversal != NULL; traversal = traversal->next) {
            printf("key : %s  value : %s\n", traversal->key, traversal->value);
        }
    }
}
