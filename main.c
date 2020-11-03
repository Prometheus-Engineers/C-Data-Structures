#include<stdio.h>
#include"sorting.h"
#include"searching.h"

int main(void)
{
	int vector[] = {5, 3, 7, 9, 2, 8, 4, 1};
	const int N = sizeof(vector) / sizeof(int);
	
	shell_sort(vector, N);
	print_array(vector, N);

	int to_search = 2;
	int index = binary_search(vector, N, to_search);
	printf("%d is in the %d index\n", to_search, index);

	return 0;
}
