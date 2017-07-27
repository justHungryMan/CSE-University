#include "jArray.h"

JunArray *junArrayNew (int capacity) {
    JunArray *arr = (JunArray *)malloc(sizeof(JunArray));
    arr->size = 0;
    arr->capacity = capacity;
    arr->data = (int *)malloc(sizeof(int) * capacity);
    for (int i = 0; i < capacity; ++i) {              // initial data : 0;
      *(arr->data + i) = 0;
    }
    return arr;
}

int junArraySize(JunArray *arr) {
  return arr->size;
}

int junArrayCapacity(JunArray *arr) {
  return arr->capacity;
}

bool junArrayIsEmpty(JunArray *arr) {
  if (arr->size == 0) return true;
  else return false;
}

int junArrayAt(JunArray *arr, int index) {
  return *(arr->data + index);
}

void junArrayPush(JunArray *arr, int element) {
  *(arr->data + (arr->size)++) = element;       // input data to arr->data + arrSize
  junArrayResize(arr, junArrayCapacity(arr));   // and then, arrSize++
}

void junArrayInsert(JunArray *arr, int index, int element) {
  int *tempArr = (int *)malloc(sizeof(int) * arr->capacity);
  int tempArrIndex = 0;
  for (int i = 0; i < arr->size; ++i) {
    if (i == index) tempArr[tempArrIndex++] = element;
    tempArr[tempArrIndex++] = junArrayAt(arr, i);             // copy data
  }
  free(arr->data);
  arr->data = tempArr;
  arr->size = tempArrIndex;
  junArrayResize(arr, junArrayCapacity(arr));
}

void junArrayPrepend(JunArray *arr, int element) {
  junArrayInsert(arr, 0, element);
}

void junArrayPop(JunArray *arr) {
  assert(arr->size != 0);
  arr->size--;
  junArrayResize(arr, junArrayCapacity(arr));
}

void junArrayDelete(JunArray *arr, int index) {
  for (int i = index; i < arr->size - 1; ++i) {
    *(arr->data + i) = junArrayAt(arr, i + 1);
  }
  arr->size--;
  junArrayResize(arr, junArrayCapacity(arr));
}

void junArrayRemove(JunArray *arr, int element) {
  int *removedArr = (int *)malloc(sizeof(int) * arr->size);
  int index = 0;
  for (int i = 0; i < arr->size; ++i) {
    if (*(arr->data + i) != element) removedArr[index++] = junArrayAt(arr, i);    // copy data except element
  }
  arr->size = index;
  free(arr->data);
  arr->data = removedArr;
  junArrayResize(arr, junArrayCapacity(arr));
}

int junArrayFind(JunArray *arr, int element) {
  for (int i = 0; i < arr->size; ++i) {
    if (junArrayAt(arr, i) == element) return i;
  }
  return -1;
}

void junArrayResize(JunArray *arr, int newCapacity) {
  int *resizedArr;
  bool isResized = false;
  if (arr->size == arr->capacity) {
    arr->capacity = arr->capacity << 1;       // double the size
    isResized = true;
  }
  else if (arr->size == arr->capacity / 4 && arr->capacity > VEC_INIT_CAPACITY * 4) { // if size is 1/4 of capacity
    arr->capacity = arr->capacity >> 1;       // resize to half
    isResized = true;
  }
  if (isResized) {
    resizedArr = (int *)malloc(sizeof(int) * arr->capacity);
    for (int i = 0; i < arr->size; ++i) {
      *(resizedArr + i) = junArrayAt(arr, i);   // copy data;
    }
    for (int i = arr->size; i < arr->capacity; ++i) *(resizedArr + i) = 0;    // initial data = 0
    free(arr->data);
    arr->data = resizedArr;
  }
}

void junArrayDestroy(JunArray *arr) {
  free(arr->data);
  free(arr);
}

// TEST ===============================================

void testAll() {
  testNew(junArrayNew(VEC_INIT_CAPACITY));
  testSize(junArrayNew(VEC_INIT_CAPACITY));
  testPush(junArrayNew(VEC_INIT_CAPACITY));
  testCapacity(junArrayNew(VEC_INIT_CAPACITY));
  testIsEmpty(junArrayNew(VEC_INIT_CAPACITY));
  testInsert(junArrayNew(VEC_INIT_CAPACITY));
  testPrepend(junArrayNew(VEC_INIT_CAPACITY));
  testPop(junArrayNew(VEC_INIT_CAPACITY));
  testDelete(junArrayNew(VEC_INIT_CAPACITY));
  testFind(junArrayNew(VEC_INIT_CAPACITY));
  testRemove(junArrayNew(VEC_INIT_CAPACITY));
  testResize(junArrayNew(VEC_INIT_CAPACITY));
}

void testNew(JunArray *arr) {
  printf("test New....");
  assert(arr->size == 0);
  assert(arr->capacity == VEC_INIT_CAPACITY);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testSize(JunArray *arr) {
  printf("test Size....");
  assert(arr->size == 0);
  for (int i = 0; i < 7; ++i) junArrayPush(arr, i);
  assert(arr->size == 7);
  junArrayRemove(arr, 3);
  assert(arr->size == 6);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testPush(JunArray *arr) {
  printf("test Push....");
  for (int i = 0; i < 32; ++i) {
    junArrayPush(arr, i);
    assert(junArrayAt(arr, i) == i);
    assert(arr->size == i + 1);
  }
  junArrayDestroy(arr);
  printf("OK\n");
}

void testCapacity(JunArray *arr) {
  printf("test Capacity....");
  assert(arr->capacity == VEC_INIT_CAPACITY);
  for (int i = 0; i < 16; ++i) {
    junArrayPush(arr, i);
  }
  assert(arr->size == 16);
  for (int i = 0; i < 8; ++i) {
    junArrayPop(arr);
  }
  assert(arr->size == 8);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testIsEmpty(JunArray *arr) {
  printf("test IsEmpty....");
  assert(junArrayIsEmpty(arr) == true);
  junArrayPush(arr, 1);
  assert(junArrayIsEmpty(arr) == false);
  junArrayDestroy(arr);
  printf("Ok\n");
}

void testAt(JunArray *arr) {
  printf("test At....");
  for (int i = 0; i < 10; ++i) {
    junArrayPush(arr, i);
  }
  assert(junArrayAt(arr, 5) == 5);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testInsert(JunArray *arr) {
  printf("test Insert....");
  for (int i = 0; i < 5; ++i) {
    junArrayPush(arr, i + 1);
  }
  junArrayInsert(arr, 2, 47);
  assert(junArrayAt(arr, 2) == 47);
  assert(junArrayAt(arr, 3) == 3);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testPrepend(JunArray *arr) {
  printf("Test Prepend....");
  for (int i = 0; i < 5; ++i) {
    junArrayPush(arr, i);
  }
  junArrayPrepend(arr, 10);
  assert(junArrayAt(arr, 0) == 10);
  assert(junArrayAt(arr, 2) == 1);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testPop(JunArray *arr) {
  printf("Test Pop....");
  for (int i = 0; i < 5; ++i) {
    junArrayPush(arr, i);
  }
  junArrayPop(arr);
  assert(junArrayAt(arr, 3) == 3);
  for (int i = 0; i < 4; ++i) {
    junArrayPop(arr);
  }
  assert(junArrayIsEmpty(arr) == true);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testDelete(JunArray *arr) {
  printf("Test Delete....");
  for (int i = 0; i < 5; ++i) {
    junArrayPush(arr, i);
  }
  junArrayDelete(arr, 3);
  assert(junArraySize(arr) == 4);
  assert(junArrayAt(arr, 3) == 4);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testRemove(JunArray *arr) {
  printf("Test Remove....");
  junArrayPush(arr, 12);
  junArrayPush(arr, 1);
  junArrayPush(arr, 4);
  junArrayPush(arr, 12);
  junArrayPush(arr, 12);
  junArrayRemove(arr, 12);
  assert(junArraySize(arr) == 2);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testFind(JunArray *arr) {
  printf("Test Find....");
  for (int i = 0; i < 5; ++i) {
    junArrayPush(arr, i);
  }
  assert(junArrayFind(arr, 0) == 0);
  assert(junArrayFind(arr, 3) == 3);
  assert(junArrayFind(arr, 4) == 4);
  junArrayDestroy(arr);
  printf("OK\n");
}

void testResize(JunArray *arr) {
  printf("Test Resize....");
  for (int i = 0; i < 18; ++i) {
    junArrayPush(arr, i);
  }
  assert(arr->capacity == 32);
  for (int i = 0; i < 15; ++i) {
    junArrayPop(arr);
  }
  assert(arr->capacity == 16);
  junArrayDestroy(arr);
  printf("OK\n");
}
