#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node {
  int item;
  struct node *next;
} node;

typedef struct JunImplementationQueue {
  int size;
  node *head;
  node *tail;
} jQueue;

jQueue *jQueueNew();
node *jQueueAddNode(int element);
void jQueueDestroy(jQueue *queue);
void jQueueEnqueue(jQueue *queue, int element);
int jQueueDequeue(jQueue *queue);
bool jQueueEmpty(jQueue *queue);

// test ===============================

void testAll();
void testEnqueueDequeue(jQueue *queue);
void testEmpty(jQueue *queue);
