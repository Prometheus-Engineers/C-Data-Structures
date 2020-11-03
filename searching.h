#include<stdio.h>

int linear_search(int vector[], int n, int num);
int binary_search(int vector[], int n, int num);

// Linear Search Method, O(n)
int linear_search(int vector[], int n, int num)
{
	for(int i = 0; i < n; i++)
		if(vector[i] == num) return i;
	return -1;
}

// Binary Search Method, O(logn)
int binary_search(int vector[], int n, int num)
{
  int start = 0, end = n - 1, middle = 0;
  while (start <= end) {
    middle = (start + end) / 2;
    if (num == vector[middle])
      return middle;
    else if (num < vector[middle])
      end = middle - 1;
    else start = middle + 1;
  }
  return -1;
}
