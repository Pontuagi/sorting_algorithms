#include "sort.h"

/**
 * swap - function that swaps two element positions in the array
 * @a: element of array
 * @b: element of array
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
 * quick_sort_helper - a function that helps the quick_sort
 * function to sort the array.
 * @array: array to be traversed.
 * @low: first element of array
 * @high: last element of array
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto(array, low, high);

		print_array(array, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order
 * @array: array to be traversed
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
	print_array(array, size);
}
