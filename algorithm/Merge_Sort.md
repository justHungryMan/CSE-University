# Merge Sort


![Merge Sort](https://d2mxuefqeaa7sj.cloudfront.net/s_E3FFAE0F61436694EB46763FBB2D7FC988F3D1EA8D46CE16B34429A7BA5D9710_1507040626205_image.png)

---
```c++
// Sort a list from a[left] to a[right].
// Should be optimized for higher efficiency!!

void merge_sort (item_type *a, int left, int right) {
  int middle;

  if (left < right) {
   merge_sort (a, left, middle);
   merge_sort (a, middle + 1, right);

   merge(a, left, middle, right);
  }
}
item_type *buffer; // extra space for merge sort, allocated beforehand

void merge (item_type *a, int left, int middle, int right) {
  int i, i_left, i_right;

  memcpy(buffer + left, a + left, sizeof(item_type) * (right - left + 1));
  // void * memcpy ( void * destination, const void * source, size_t num );

  i_left = left;
  i_right = middle + 1;
  i = left;

  while ((i_left <= middle) && (i_right <= right)) {
    if (buffer[i_left] < buffer[i_right]) a[i++] = buffer[i_left++];
    else a[i++] = buffer[i_right++];
  }

  while (i_left <= middle) a[i++] = buffer[i_left++];
  while (i_right <= right) a[i++] = buffer[i_right++];
}
```
