int jBsearch(int arr[], int num, int min, int max) {
  int mid;
  int first = min;
  int last = max;

  while (1) {
    mid = (last - first) / 2 + first;
    if (last < first) {
      return -1;
    }
    else {
      if (arr[mid] < num) {
        first = mid + 1;
      }
      else if (arr[mid] > num) {
        last = mid - 1;
      }
      else if (arr[mid] == num) {
        return mid;
      }
    }
  }
}
