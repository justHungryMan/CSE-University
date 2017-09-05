#include "test.h"

void testAll() {
  // testAdd(jHashTableNew(TABLE_INIT_SIZE));
  // testGet(jHashTableNew(TABLE_INIT_SIZE));
  // testRemove(jHashTableNew(TABLE_INIT_SIZE));
  testDoubling(jHashTableNew(TABLE_INIT_SIZE));
}
void testAdd(jHashTable **hashTable) {
  printf("Test Add....");
  jHashTableAdd("Hyejin", "Girfriend", hashTable);
  jHashTableAdd("love", "Hyejin", hashTable);
  assert(jHashTableExists("Hyejin", hashTable) == true);
  assert(jHashTableExists("Sungjun", hashTable) == false);
  jHashTableDestroy(hashTable);
  printf("OK\n");
}
void testGet(jHashTable **hashTable) {
  printf("Test Get....");
  jHashTableAdd("Hyejin", "Girlfriend", hashTable);
  jHashTableAdd("love", "Hyejin", hashTable);
  assert((!strcmp(jHashTableGet("Hyejin", hashTable), "Girlfriend")) == true);
  assert((!strcmp(jHashTableGet("Sungjun", hashTable), "Sungjun")) == false);
  jHashTableDestroy(hashTable);
  printf("OK\n");
}
void testRemove(jHashTable **hashTable) {
  printf("Test Remove....");
  jHashTableAdd("Hyejin", "Girlfriend", hashTable);
  jHashTableAdd("love", "Hyejin", hashTable);
  assert((!strcmp(jHashTableGet("Hyejin", hashTable), "Girlfriend")) == true);
  jHashTableRemove("Hyejin", hashTable);
  assert(jHashTableExists("Hyejin", hashTable) == false);
  jHashTableDestroy(hashTable);
  printf("OK\n");
}
void testDoubling(jHashTable **hashTable) {
  printf("Test Doubling....");

  jHashTableAdd("a", "a", hashTable);
  jHashTableAdd("b", "b", hashTable);
  jHashTableAdd("c", "c", hashTable);
  jHashTableAdd("d", "d", hashTable);
  jHashTableAdd("e", "e", hashTable);
  jHashTableAdd("f", "f", hashTable);
  jHashTableAdd("g", "g", hashTable);
  jHashTableAdd("h", "h", hashTable);
  jHashTableAdd("i", "i", hashTable);
  jHashTableAdd("j", "j", hashTable);
  jHashTableAdd("k", "k", hashTable);
  jHashTableAdd("l", "l", hashTable);
  jHashTableAdd("o", "o", hashTable);
  jHashTableAdd("p", "p", hashTable);
  jHashTableAdd("q", "q", hashTable);
  jHashTableAdd("r", "r", hashTable);
  jHashTableAdd("s", "s", hashTable);
  jHashTableAdd("t", "t", hashTable);
  jHashTableAdd("u", "u", hashTable);
  jHashTableAdd("v", "v", hashTable);
  jHashTableAdd("w", "w", hashTable);
  assert((*hashTable)->capacity == 32);
  jHashTableRemove("a", hashTable);
  jHashTableRemove("b", hashTable);
  jHashTableRemove("c", hashTable);
  jHashTableRemove("d", hashTable);
  jHashTableRemove("e", hashTable);
  jHashTableRemove("f", hashTable);
  jHashTableRemove("g", hashTable);
  jHashTableRemove("h", hashTable);
  jHashTableRemove("i", hashTable);
  jHashTableRemove("j", hashTable);
  jHashTableRemove("k", hashTable);
  jHashTableRemove("l", hashTable);
  jHashTableRemove("p", hashTable);
  jHashTableRemove("q", hashTable);
  jHashTableRemove("o", hashTable);
  assert((*hashTable)->capacity == 8);
  jHashTableDestroy(hashTable);
  printf("OK\n");
}
