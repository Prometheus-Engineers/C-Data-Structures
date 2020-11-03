#include<stdio.h>
#include<stdbool.h>
#include"utilities.h"

void bubble_sort(int vector[], int n);
void selection_sort(int vector[], int n);
void insertion_sort(int vector[], int n);
void shell_sort(int vector[], int n);

// Bubble Sort Method, O(n^2)
void bubble_sort(int vector[], int n)
{
	bool swapped;
	for(int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for(int j = 0; j < n - i - 1; j++)
			if(vector[j] > vector[j + 1])
			{
				swap(&vector[j], &vector[j + 1]);
				swapped = true;
			}
		if (swapped == false)
			break;
	}
}

// Selection Sort Method, O(n^2)
void selection_sort(int vector[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int k = i;
		for(int j = i + 1; j < n; j++)
			if(vector[j] < vector[k])
				k = j;
		swap(&vector[i], &vector[k]);
	}
}

// Insertion Sort Method, O(n^2)
void insertion_sort(int vector[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int temp = vector[i], j = i - 1;
		while(j >= 0 && vector[j] > temp)
		{
			swap(&vector[j + 1], &vector[j]);
			j--;
		}
	}
}

// Shell's Insertion Sort Method, O(n^2)
void shell_sort(int vector[], int n)
{
	int step = n;
	bool end = false;
	while(step > 0)
	{
		step /= 2;
		do {
			end = true;
			for(int i = 0; i < n - step; i++)
			{
				int j = i + step;
				if (vector[i] > vector[j])
				{
					swap(&vector[i], &vector[j]);
					end = false;
				}
			}
		} while(end == false);
	}
}
