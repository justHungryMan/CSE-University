#include "jQueue.h"

jQueue *jQueueNew() {
  jQueue *newQueue = (jQueue*)malloc(sizeof(jQueue));
  newQueue->size = 0;
  newQueue->head = NULL;
  newQueue->tail = NULL;
  return newQueue;
}

node *jQueueAddNode(int element) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->item = element;
  newNode->next = NULL;
  return newNode;
}

void jQueueDestroy(jQueue *queue) {
  node *traversal;
  node *destroiedNode;
  int times = queue->size;

  if (queue->size != 0) destroiedNode = traversal = queue->tail;
  for (int i = 0; i < times; ++i) {
    traversal = traversal->next;
    free(destroiedNode);
    destroiedNode = traversal;
  }
  free(queue);
}

void jQueueEnqueue(jQueue *queue, int element) {
  node *newNode = jQueueAddNode(element);
  if (queue->size == 0) {
    queue->tail = queue->head = newNode;
  }
  else {
    newNode->next = queue->tail;
    queue->tail = newNode;
  }
  queue->size += 1;
}

int jQueueDequeue(jQueue *queue) {
  assert(queue->size != 0);
  int dequeuedItem = queue->head->item;
  node *traversal;
  if (queue->head == queue->tail) {
    free(queue->head);
    queue->head = queue->tail = NULL;
  }
  else {
    dequeuedItem = queue->head->item;
    for (traversal = queue->tail; traversal->next != queue->head; traversal = traversal->next);
    free(queue->head);
    queue->head = traversal;
  }
  queue->size -= 1;
  return dequeuedItem;
}

bool jQueueEmpty(jQueue *queue) {
  return queue->size == 0;
}

void testAll() {
  testEnqueueDequeue(jQueueNew());
  testEmpty(jQueueNew());
}

void testEnqueueDequeue(jQueue *queue) {
  printf("Test Enqueue & Dequeue....");
  jQueueEnqueue(queue, 1);
  jQueueEnqueue(queue, 2);
  jQueueEnqueue(queue, 3);
  jQueueEnqueue(queue, 4);
  assert(jQueueDequeue(queue) == 1);
  assert(jQueueDequeue(queue) == 2);
  assert(queue->size == 2);
  jQueueDestroy(queue);
  printf("OK\n");
}

void testEmpty(jQueue *queue) {
  printf("Test Empty....");
  assert(jQueueEmpty(queue) == true);
  jQueueEnqueue(queue, 1);
  assert(jQueueEmpty(queue) == false);
  jQueueDestroy(queue);
  printf("OK\n");
}
