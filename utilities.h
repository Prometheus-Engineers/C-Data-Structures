#include<stdio.h>

void print_array(int vector[], int n);
void swap(int *a, int *b);

// Swap two int variables values
void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

// Print an array of n size
void print_array(int vector[], int n)
{
	printf("[");
	for(int i = 0; i < n; i++)
		printf(" %d,", vector[i]);
	puts(" ]");
}
