#include "jLinkedlist.h"

jLinkedlist *jLinkedlistNew () {
  jLinkedlist *newLinkedlist = (jLinkedlist *)malloc(sizeof(jLinkedlist));
  newLinkedlist->size = 0;
  newLinkedlist->first = NULL;
  newLinkedlist->last = NULL;
  return newLinkedlist;
}

void jLinkedlistDestroy(jLinkedlist *head) {
  node *destroiedNode, *traversalNode;

  for (traversalNode = head->first; traversalNode != NULL;) {
    destroiedNode = traversalNode;
    traversalNode = traversalNode->next;
    free(destroiedNode);
  }
  free(head);
  //assert(head == NULL);
}

node *jLinkedlistAddNode(int element) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->item = element;
  newNode->next = NULL;
  return newNode;
}

int jLinkedlistSize(jLinkedlist *head) {
  return head->size;
}

bool jLinkedlistEmpty(jLinkedlist *head) {
  assert((head->size == 0) == ((head->first == NULL) && (head->last == NULL)));
  return head->size == 0 && head->first == NULL && head->last == NULL;
}

int jLinkedlistValueAt(jLinkedlist *head, int times) {
  node *traversal;
  traversal = head->first;
  assert(head->size >= times + 1);
  while(--times >= 0) {
    traversal = traversal->next;
    assert(traversal != NULL);
  }
  return traversal-> item;
}

void jLinkedlistPushFront(jLinkedlist *head, int element) {
  if (head->size == 0) {
    head->first = head->last = jLinkedlistAddNode(element);
  }
  else {
    node *newNode = jLinkedlistAddNode(element);
    newNode->next = head->first;
    head->first = newNode;
  }
  head->size += 1;
}

int jLinkedlistPopFront(jLinkedlist *head) {
  assert(head->size > 0);
  int popedItem = head->first->item;
  node *destroiedNode = head->first;
  head->first = head->first->next;
  if (head->first == NULL) head->last = NULL;

  free(destroiedNode);
  head->size -= 1;
  return popedItem;
}

void jLinkedlistPushBack(jLinkedlist *head, int element) {
  if (head->size == 0) {
    head->first = head->last = jLinkedlistAddNode(element);
  }
  else {
    head->last->next = jLinkedlistAddNode(element);
    head->last = head->last->next;
  }
  head->size += 1;
}

int jLinkedlistPopBack(jLinkedlist *head) {
  assert(head->size != 0 && (head->first !=NULL && head->last != NULL));
  int popedItem = head->last->item;
  node *traversal = head->first;
  for (; traversal->next != head->last; traversal = traversal->next);
  free(traversal->next);
  head->last = traversal;
  head->last->next = NULL;
  if (head->last == NULL) head->first = NULL;
  head->size -= 1;
  return popedItem;
}

int jLinkedlistFront(jLinkedlist *head) {
  assert(head->size != 0 && head->first != NULL && head->last != NULL);
  return head->first->item;
}

int jLinkedlistBack(jLinkedlist *head) {
  assert(head->size != 0 && head->first != NULL && head->last != NULL);
  return head->last->item;
}

void jLinkedlistInsert(jLinkedlist *head, int index, int value) {
  assert(head->size >= index && index >= 0);
  if (index == 0) {
    jLinkedlistPushFront(head, value);
  } //  no element in linkedlist
  else if (index == head->size) {
    jLinkedlistPushBack(head, value);
  }
  else {
    node *traversal = head->first;
    node *newNode = jLinkedlistAddNode(value);
    for (int i = 0; i < index - 1; traversal = traversal->next, ++i);
    newNode->next = traversal->next;
    traversal->next = newNode;
    head->size += 1;
  }
}

void jLinkedlistErase(jLinkedlist *head, int index) {
  assert(index >= 0 && head->size > index);
  if (index == 0) {
    jLinkedlistPopFront(head);
  }
  else if (index == head->size - 1) {
    jLinkedlistPopBack(head);
  }
  else {
    node *traversal = head->first;
    node *destroiedNode;
    for (int i = 0; i < index - 1; traversal = traversal->next, ++i);
    destroiedNode = traversal->next;
    traversal->next = traversal->next->next;
    free(destroiedNode);
    head->size -= 1;
  }
}

int jLinkedlistValueNFromEnd(jLinkedlist *head, int index) {
  return jLinkedlistValueAt(head, head->size - index - 1);
}

void jLinkedlistReverse(jLinkedlist *head) {
  int times = head->size;
  for (int i = 0; i < times; ++i) {
    jLinkedlistInsert(head, i, jLinkedlistPopBack(head));
  }
}

void jLinkedlistRemoveValue(jLinkedlist *head, int value) {
  bool isRemoved = false;
  node *traversal;
  int count = 0;
  for (traversal = head->first; traversal != NULL; traversal = traversal->next, ++count) {
    if (traversal->item == value) {
      isRemoved = true;
      break;
    }
  }
  assert(isRemoved == true);
  jLinkedlistErase(head, count);
}

// Test Code==============================================================

void testAll() {
  testSize(jLinkedlistNew());
  testValueAt(jLinkedlistNew());
  testPopFront(jLinkedlistNew());
  testPopBack(jLinkedlistNew());
  testFrontBack(jLinkedlistNew());
  testInsert(jLinkedlistNew());
  testErase(jLinkedlistNew());
  testValueNFromEnd(jLinkedlistNew());
  testReverse(jLinkedlistNew());
  testRemoveValue(jLinkedlistNew());
}

void testSize(jLinkedlist *head) {
  printf("Test Size & Empty....");
  assert(jLinkedlistEmpty(head) == true);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 2);
  assert(jLinkedlistSize(head) == 2);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testValueAt(jLinkedlist *head) {
   printf("Test ValueAt....");
   jLinkedlistPushFront(head, 3);
   jLinkedlistPushFront(head, 2);
   jLinkedlistPushFront(head, 1);
   assert(jLinkedlistValueAt(head, 2) == 3);
   assert(jLinkedlistValueAt(head, 1) == 2);
   jLinkedlistDestroy(head);
   printf("OK\n");
}

void testPopFront(jLinkedlist *head) {
  printf("Test Pop_front....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  assert(jLinkedlistPopFront(head) == 1);
  assert(jLinkedlistValueAt(head, 0) == 2);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testPopBack(jLinkedlist *head) {
  printf("Test Pop_Back....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 4);
  jLinkedlistPushBack(head, 7);
  assert(jLinkedlistPopBack(head) == 7);
  assert(jLinkedlistPopBack(head) == 3);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testFrontBack(jLinkedlist *head) {
  printf("Test Front & Back....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 4);
  jLinkedlistPushBack(head, 7);
  assert(jLinkedlistFront(head) == 4);
  assert(jLinkedlistBack(head) == 7);
  jLinkedlistPopFront(head);
  assert(jLinkedlistFront(head) == 1);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testInsert(jLinkedlist *head) {
  printf("Test Insert....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 4);
  jLinkedlistPushBack(head, 7);
  jLinkedlistInsert(head, 3, 10);
  assert(jLinkedlistValueAt(head, 3) == 10);
  assert(jLinkedlistValueAt(head, 4) == 3);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testErase(jLinkedlist *head) {
  printf("Test Erase....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 4);
  jLinkedlistPushBack(head, 7);
  jLinkedlistInsert(head, 3, 10);
  jLinkedlistErase(head, 4);
  assert(jLinkedlistValueAt(head, 4) == 7);
  jLinkedlistErase(head, 0);
  assert(jLinkedlistValueAt(head, 0) == 1);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testValueNFromEnd(jLinkedlist *head) {
  printf("Test value n from end....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 4);
  jLinkedlistPushBack(head, 7);
  jLinkedlistInsert(head, 3, 10);
  assert(jLinkedlistValueNFromEnd(head, 1) == 3);
  assert(jLinkedlistValueNFromEnd(head, 4) == 1);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testReverse(jLinkedlist *head) {
  printf("Test Reverse....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 4);
  jLinkedlistPushBack(head, 7);
  jLinkedlistInsert(head, 3, 10);
  jLinkedlistReverse(head);
  assert(jLinkedlistValueAt(head, 1) == 3);
  assert(jLinkedlistValueAt(head, 4) == 1);
  jLinkedlistDestroy(head);
  printf("OK\n");
}

void testRemoveValue(jLinkedlist *head) {
  printf("Test RemoveValue....");
  jLinkedlistPushFront(head, 3);
  jLinkedlistPushFront(head, 2);
  jLinkedlistPushFront(head, 1);
  jLinkedlistPushFront(head, 4);
  jLinkedlistPushBack(head, 7);
  jLinkedlistInsert(head, 3, 10);
  jLinkedlistRemoveValue(head, 2);
  assert(jLinkedlistValueAt(head, 1) == 1);
  assert(jLinkedlistValueAt(head, 2) == 10);
  jLinkedlistDestroy(head);
  printf("OK\n");
}
