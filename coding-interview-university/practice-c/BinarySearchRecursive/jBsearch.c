int jBsearch(int arr[], int num, int min, int max) {
  int mid = (max - min) / 2 + min;
  if (min > max) return -1;
  else {
    if (num > arr[mid]) return jBsearch(arr, num, mid + 1, max);
    else if (num < arr[mid]) return jBsearch(arr, num, min, mid - 1);
    else if (num == arr[mid]) return mid;
  }
  return -1;
}
