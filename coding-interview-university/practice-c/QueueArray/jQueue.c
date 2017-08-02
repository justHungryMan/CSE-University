#include "jQueue.h"

jQueue *jQueueNew() {
  jQueue *newQueue = (jQueue*)malloc(sizeof(newQueue));
  newQueue->head = 0;
  newQueue->tail = 0;
  newQueue->items = (int *)malloc(sizeof(int) * QUEUE_MAX_SIZE);
  return newQueue;
}

void jQueueDestroy(jQueue *queue) {
  free(queue->items);
  free(queue);
}

void jQueueEnqueue(jQueue *queue, int element) {
  assert(queue->head % QUEUE_MAX_SIZE != (queue->tail + 1) % QUEUE_MAX_SIZE); // queue overflow check
  queue->items[queue->tail++ % QUEUE_MAX_SIZE] = element;

}

int jQueueDequeue(jQueue *queue) {
  assert(queue->head % QUEUE_MAX_SIZE != queue->tail % QUEUE_MAX_SIZE); //  size 0 check
  int dequeuedItem = queue->items[queue->head++ % QUEUE_MAX_SIZE];
  return dequeuedItem;
}

bool jQueueEmpty(jQueue *queue) {
  return queue->head == queue->tail;
}
bool jQueueFull(jQueue *queue) {
  return queue->head % QUEUE_MAX_SIZE == (queue->tail + 1) % QUEUE_MAX_SIZE;
}

void testAll() {
  testEnqueue(jQueueNew());
  testDequeue(jQueueNew());
  testEmpty(jQueueNew());
  testFull(jQueueNew());
}

void testEnqueue(jQueue *queue) {
  printf("Test Endqueue....");
  assert(jQueueEmpty(queue) == true);
  jQueueEnqueue(queue, 3);
  jQueueEnqueue(queue, 4);
  assert(jQueueEmpty(queue) == false);
  jQueueDestroy(queue);
  printf("OK\n");
}
void testDequeue(jQueue *queue) {
  printf("Test Dedqueue....");
  assert(jQueueEmpty(queue) == true);
  jQueueEnqueue(queue, 3);
  jQueueEnqueue(queue, 4);
  assert(jQueueEmpty(queue) == false);
  jQueueDequeue(queue);
  assert(jQueueDequeue(queue) == 4);
  assert(jQueueEmpty(queue) == true);
  jQueueDestroy(queue);
  printf("OK\n");
}
void testEmpty(jQueue *queue) {
  printf("Test Empty....");
  assert(jQueueEmpty(queue) == true);
  jQueueEnqueue(queue, 4);
  assert(jQueueEmpty(queue) == false);
  jQueueDestroy(queue);
  printf("OK\n");
}
void testFull(jQueue *queue) {
  printf("Test Full....");
  for (int i = 0; i < QUEUE_MAX_SIZE - 1; ++i) {
    jQueueEnqueue(queue, i);
  }
  assert(jQueueFull(queue) == true);
  jQueueDestroy(queue);
  printf("OK\n");
}
