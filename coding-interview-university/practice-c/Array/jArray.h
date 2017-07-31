#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define VEC_INIT_CAPACITY 4

// URL : https://github.com/jun-Sogang/CSE-University/tree/master/coding-interview-university#data-structures

typedef struct JunImplementationArray {
  int size;
  int capacity;
  int *data;
} JunArray;

JunArray *junArrayNew (int capacity);
int junArraySize(JunArray *arr);
int junArrayCapacity(JunArray *arr);
bool junArrayIsEmpty(JunArray *arr);
void junArrayPush(JunArray *arr, int element);
void junArrayInsert(JunArray *arr, int index, int element);
void junArrayPrepend(JunArray *arr, int element);
void junArrayPop(JunArray *arr);
void junArrayDelete(JunArray *arr, int index);
void junArrayRemove(JunArray *arr, int element);
int junArrayFind(JunArray *arr, int element);
void junArrayResize(JunArray *arr, int newCapacity);
void junArrayDestroy(JunArray *arr);

void testAll();
void testNew(JunArray *arr);
void testSize(JunArray *arr);
void testPush(JunArray *arr);
void testCapacity(JunArray *arr);
void testIsEmpty(JunArray *arr);
void testInsert(JunArray *arr);
void testPrepend(JunArray *arr);
void testPop(JunArray *arr);
void testDelete(JunArray *arr);
void testFind(JunArray *arr);
void testRemove(JunArray *arr);
void testResize(JunArray *arr);
