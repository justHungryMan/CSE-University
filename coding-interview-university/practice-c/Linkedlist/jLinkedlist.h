#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct node {
  int item;
  struct node *next;
} node;

typedef struct jLinkedlist {
  int size;
  node *first;
  node *last;
} jLinkedlist;

jLinkedlist *jLinkedlistNew ();
void jLinkedlistDestroy(jLinkedlist *head);
node *jLinkedlistAddNode(int element);
int jLinkedlistSize(jLinkedlist *head);
bool jLinkedlistEmpty(jLinkedlist *head);
int jLinkedlistValueAt(jLinkedlist *head, int times);
void jLinkedlistPushFront(jLinkedlist *head, int element);
int jLinkedListPopFront(jLinkedlist *head);
void jLinkedlistPushBack(jLinkedlist *head, int element);
int jLinkedlistPopBack(jLinkedlist *head);
int jLinkedlistFront(jLinkedlist *head);
int jLinkedlistBack(jLinkedlist *head);
void jLinkedlistInsert(jLinkedlist *head, int index, int value);
int jLinkedlistValueNFromEnd(jLinkedlist *head, int index);
void jLinkedlistReverse(jLinkedlist *head);
void jLinkedlistRemoveValue(jLinkedlist *head, int value);

void testAll();
void testSize(jLinkedlist *head);
void testValueAt(jLinkedlist *head);
void testPopFront(jLinkedlist *head);
void testPopBack(jLinkedlist *head);
void testFrontBack(jLinkedlist *head);
void testInsert(jLinkedlist *head);
void testErase(jLinkedlist *head);
void testValueNFromEnd(jLinkedlist *head);
void testReverse(jLinkedlist *head);
void testRemoveValue(jLinkedlist *head);
