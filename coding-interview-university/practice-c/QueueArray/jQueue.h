#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#define QUEUE_MAX_SIZE 16

typedef struct jQueue {
  int head;
  int tail;
  int *items;
} jQueue;

jQueue *jQueueNew();
void jQueueDestroy(jQueue *queue);
void jQueueEnqueue(jQueue *queue, int element);
int jQueueDequeue(jQueue *queue);
bool jQueueEmpty(jQueue *queue);
bool jQueueFull(jQueue *queue);

void testAll();
void testEnqueue(jQueue *queue);
void testDequeue(jQueue *queue);
void testEmpty(jQueue *queue);
void testFull(jQueue *queue);
