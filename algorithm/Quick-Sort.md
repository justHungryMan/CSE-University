# Quick Sort

![](https://d2mxuefqeaa7sj.cloudfront.net/s_F0BC68418A661984FFF0BA922A1F1B1A466D2563C6927C7FBCE2D5BE1D9FCA01_1507108362018_image.png)

----------
    // Sort a list from a[left] to a[right]
    // Should be optimized for higher efficiency!!
    
    void quick_sort (int *a, int left, int right) {
      int pivot;
      if (left < right) {
        pivot = partition(a, left, right);
        
        quick_sort(a, left, pivot - 1);
        quick_sort(a, pivot + 1, right);
      }
    }
    
    #define SWAP(a, b) { int temp; temp = a; a = b; b = temp; }
    
    int partition (int *a, int left, int right) {
      int i, pivot;
      
      pivot = left;
      for (i = left; i < right; i++) {
        if (a[i] < a[right]) {
          SWAP(a[i], a[pivot]);
          pivot += 1;
        }
      }
      SWAP(a[right], a[pivot]);
      return pivot;
    }

`이 함수는 무엇을 기준으로 pivot을 잡을까?` 

- 

Worst-case running time


![worst-case running time](https://d2mxuefqeaa7sj.cloudfront.net/s_F0BC68418A661984FFF0BA922A1F1B1A466D2563C6927C7FBCE2D5BE1D9FCA01_1507114150815_image.png)


Best-case running time

- merge sort 와 같다.



