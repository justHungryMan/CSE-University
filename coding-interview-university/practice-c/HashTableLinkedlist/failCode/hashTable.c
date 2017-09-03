#include "hashTable.h"

jHashTable *jHashTableNew(int capacity) {
    jHashTable *newHashTable = (jHashTable*)malloc(sizeof(jHashTable));
    newHashTable->capacity = capacity;
    newHashTable->size = 0;
    newHashTable->data = (chaining**)malloc(sizeof(chaining*) * capacity);
    for (int i = 0; i < capacity; ++i) {
        newHashTable->data[i] = NULL;
    }
    return newHashTable;
}

void jHashTableDoubling(jHashTable *hashTable) {
    bool isDoubleing = false;
    int doublingSize;
    if (hashTable->size == hashTable->capacity) {
        isDoubleing = true;
        doublingSize = hashTable->capacity * 2;
    }
    else if (hashTable->size == hashTable->capacity / 4 && hashTable->capacity >= 32) {
        isDoubleing = true;
        doublingSize = hashTable->capacity / 4;
    }
    if (isDoubleing) {
        jHashTable *newHashTable = jHashTableNew(doublingSize);
        int data[hashTable->capacity * 2];
        for (int i = 0; i < hashTable->capacity; ++i) {
            for (chaining *traversal = hashTable->data[i]; traversal != NULL; traversal = traversal->next) {
                jHashTableAdd(traversal->key, traversal->value, newHashTable);
            }
        }
        jHashTableDestroyData(hashTable);
        hashTable->data = (chaining**)realloc(hashTable->data, sizeof(chaining*) * doublingSize);
        for (int i = 0; i < doublingSize; ++i) {
            hashTable->data[i] = NULL;
        }
        hashTable->size = 0;
        hashTable->capacity = doublingSize;
        for (int i = 0; i < newHashTable->capacity; ++i) {
            for (chaining *traversal = newHashTable->data[i]; traversal != NULL; traversal = traversal->next) {
                jHashTableAdd(traversal->key, traversal->value, hashTable);
            }
        }
        jHashTableDestroy(newHashTable);
    }
}

void jHashTableDestroy(jHashTable *hashTable) {
    jHashTableDestroyData(hashTable);
    free(hashTable->data);
    free(hashTable);
}

void jHashTableDestroyData(jHashTable *hashTable) {
  for (int i = 0; i < hashTable->capacity; ++i) {
      for (chaining *traversal = hashTable->data[i]; traversal != NULL;) {
          chaining *deletedChain = traversal;
          traversal = traversal->next;
          free(deletedChain->key);
          free(deletedChain->value);
          free(deletedChain);
      }
  }
}

int hash(const char* key, const int m) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        hash = hash * 31 + key[i];
    }
    return abs(hash % m);
}

chaining *jHashTableAddChain(const char* key, const char* value) {
    int valueLen = strlen(value);
    int keyLen = strlen(key);
    chaining *newChain = (chaining *)malloc(sizeof(chaining));
    newChain->value = (char *)malloc(sizeof(char) * (valueLen + 1));
    newChain->key = (char *)malloc(sizeof(char) * (keyLen + 1));
    newChain->next = NULL;
    strncpy(newChain->value, value, valueLen + 1);
    strncpy(newChain->key, key, valueLen + 1);
    return newChain;
}

void jHashTableAdd(char *key, char *value, jHashTable *hashTable) {
    int hashedKey = hash(key, hashTable->capacity);
    bool isKeyExist = false;
    chaining *findLastChain = hashTable->data[hashedKey];
    if (findLastChain == NULL) {
        hashTable->data[hashedKey] = jHashTableAddChain(key, value); // 여기가 문제! find last chain -> next로 할당 해야 할 것 같음.
        hashTable->size += 1;
        jHashTableDoubling(hashTable);
    }
    else {
        for (findLastChain = hashTable->data[hashedKey]; findLastChain->next != NULL; findLastChain = findLastChain->next) {
            if (!strcmp(findLastChain->key, key)) {
                strncpy(findLastChain->value, value, strlen(value) + 1);
                isKeyExist = true;
                break;
            }
        }
        if (isKeyExist == false) {
            findLastChain->next = jHashTableAddChain(key, value);
            findLastChain = findLastChain->next;
            hashTable->size += 1;
            jHashTableDoubling(hashTable);
        }
    }
}

bool jHashTableExists(const char *key, jHashTable *hashTable) {
    int hashedKey = hash(key, hashTable->capacity);
    for (chaining *traversal = hashTable->data[hashedKey]; traversal != NULL; traversal = traversal->next) {
        if (!strcmp(traversal->key, key)) return true;
    }
    return false;
}

char *jHashTableGet(const char *key, jHashTable *hashTable) {
    int hashedKey = hash(key, hashTable->capacity);
    for (chaining *traversal = hashTable->data[hashedKey]; traversal != NULL; traversal = traversal->next) {
        if (!strcmp(traversal->key, key)) return traversal->value;
    }
    return "NULL";
}

void jHashTableRemove(const char *key, jHashTable *hashTable) {
    assert(jHashTableExists(key, hashTable) == true);
    int hashedKey = hash(key, hashTable->capacity);
    if (!strcmp(hashTable->data[hashedKey]->key, key)) {
        free(hashTable->data[hashedKey]->key);
        free(hashTable->data[hashedKey]->value);
        free(hashTable->data[hashedKey]);
        hashTable->data[hashedKey] = NULL;
    }
    else {
        chaining *traversal, *prev;
        for (prev = hashTable->data[hashedKey], traversal = hashTable->data[hashedKey]->next; !strcmp(traversal->key, key); traversal = traversal->next);
        free(traversal->key);
        free(traversal->value);
        prev->next = traversal->next;
        free(traversal);
    }
    hashTable->size -= 1;
    jHashTableDoubling(hashTable);
}

void showHashTable(jHashTable *hashTable) {
    printf("===\nshow Table\n\n");
    for (int i = 0; i < hashTable->capacity; ++i) {
        printf("===   index : %d\n", i);
        for (chaining *traversal = hashTable->data[i]; traversal != NULL; traversal = traversal->next) {
            printf("key : %s  value : %s\n", traversal->key, traversal->value);
        }
    }
}
