# Maximum Subsequence Sum
Problem

![](https://d2mxuefqeaa7sj.cloudfront.net/s_2C8CCF3EFF3C360B6E06139916F9C7FBB907B5CE7705F2EF8B346151C2B9B476_1507036470907_image.png)

----------
## Algorithm 1
- Strategy
  - Enumerate all possibilities one at a time
  - No efficiency is considered, resulting in a lot of unnecessary computation

O(n^3)

```c++
int maxSubsequenceSum (const int a[], int n) {
  int thisSum, maxSum, i, j, k;
  maxSum = 0;
  for (i = 0; i < n; ++i) {
    for (j = i; j < n; ++j) {
      thisSum = 0;
      for (k = i; k <= j; ++k) {
        thisSum += a[k];
        if (thisSum > maxSum) maxSum = thisSum;
      }
    }
  }
  return maxSum;
}
```

----------
## Algorithm 2
- Strategy
  - Get rid of the inefficiency in the innermost for-loop

O(n^2)

```c++
int maxSubsequenceSum (const int a[], int n) {
  int thisSum, maxSum, i, j, k;
  maxSum = 0;
  for (i = 0; i < n; ++i) {
    thisSum = 0;
    for (j = i; j < n; ++j) {
      thisSum += a[j];
      if (thisSum >= maxSum) maxSum = thisSum;
    }
  }
  return maxSum;
}
```

----------
## Algorithm 3
- Strategy
  - Use the Divide-and-Conquer strategy
    - The maximum subsequence sum can be in one of three places

O(nlogn)

```c++
static int maxSubSum (const int a[], int left, int right) {
  int maxLeftSum, maxRightSum;
  int maxLeftBorderSum, maxRightBorderSum;
  int leftBorderSum, rightBorderSum;
  int center, i;

  if (left == right) {
    return a[left] > 0 ? a[left] : 0;
  }

  center = (left + right) / 2;
  maxLeftSum = maxSubSum(a, left, center);
  maxRightSum = maxSubsum(a, center + 1, right);

  maxLeftBorderSum = leftBorderSum = 0;
  for (i = center; i >= left; --i) {
    leftBorderSum += a[i];
    if (leftBorderSum > maxLeftBorderSum) {
      maxLeftBorderSum = leftBorderSum;
    }
  }
  maxRightBorderSum = rightBorderSum = 0;
  for (i = center + 1; i <= right; ++i) {
    rightBorderSum += a[i];
    if (rightBorderSum > maxRightBorderSum) {
      maxRightBorderSum = rightBorderSum;
    }
  }
  return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int maxSubsequenceSum (const int a[], int n) {
  return maxSubSum(a, 0, n - 1);
}
```


![O(nlogn) 증명](https://d2mxuefqeaa7sj.cloudfront.net/s_2C8CCF3EFF3C360B6E06139916F9C7FBB907B5CE7705F2EF8B346151C2B9B476_1507037981212_image.png)

----------
## Algorithm 4
- Strategy
  - Use the Dynamic Programming strategy

O(nlogn)

```c++
int maxSubsequenceSum (const int a[], int n) {
  int thisSum, maxSum, i;
  thisSum = maxSum = 0;
  for (i = 0; i < n; ++i) {
    thisSum += a[j];
    if (thisSum > maxSum) maxSum = thisSum;
    else if (thisSum < 0) thisSum = 0;
  }
  return maxSum;
}
```
