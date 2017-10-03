# Analysis of Fibonacci
피보나치 수열의 복잡도를 구해본다.

## Recursive
    int fib (int n) {
      if (n == 0) return 0;
      else if (n == 1) return 1;
      else return fib(n - 1) + fib (n - 2);
    }



![피보나치수열의 구조](https://d2mxuefqeaa7sj.cloudfront.net/s_4208F6B523CA62F0B3B7697FDA4B605DE404B424D3BBAD47490239E1A9449347_1507034795857_image.png)

![O(2^n) 증명](https://d2mxuefqeaa7sj.cloudfront.net/s_4208F6B523CA62F0B3B7697FDA4B605DE404B424D3BBAD47490239E1A9449347_1507035890832_image.png)
