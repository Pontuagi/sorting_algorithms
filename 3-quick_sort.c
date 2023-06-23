#include "sort.h"

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
	int temp;
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	return (i + 1);
}

/**
  * quick_sort - a function to sort an array in ascending order using quick
  * sort
  * @array: the array to sort
  * @size: the size of the array
  */
void quick_sort(int *array, size_t size)
{
	int pivot_idx;

	if (array == NULL || size <= 1)
		return;

	pivot_idx = lomuto(array, 0, size - 1);
	quick_sort(array, pivot_idx);
	quick_sort(array + pivot_idx + 1, size - pivot_idx - 1);

}
