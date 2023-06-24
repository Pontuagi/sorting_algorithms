#include "sort.h"

/**
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
  * lomuto - function to divide an array into two based on pivot. all numbers
  * above pivot on the right and the rest on the left
  * @array: the array to divide
  * @low: the lower index
  * @high: the high index of the pivot
  *
  * Return: the index of the pivot after partitioning
  */
int lomuto(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] <= pivot)
		{
			++i;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 */
void quick_sort_helper(int *array, int low, int high)
{
	int i, pi;

	if (low < high)
	{
		pi = lomuto(array, low, high);

		for (i = low; i <= high; ++i)
		{
			printf("%d ", array[i]);
		}
		printf("\n");

		quick_sort_helper(array, low, pi - 1);
		quick_sort_helper(array, pi + 1, high);
	}
}

/**
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
	print_array(array, size);
}
