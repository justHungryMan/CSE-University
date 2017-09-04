#include "test.h"

void testBsearch() {
  printf("test Binary Search...");
  int arr[10];
  int temp = 2;
  for (int i = 0; i < 10; ++ i) {
    arr[i] = temp;
    temp *= 2;
  }
  assert(jBsearch(arr, 16, 0, 9) == 3);
  assert(jBsearch(arr, 128, 0, 9) == 6);
  printf("Ok\n");
}
