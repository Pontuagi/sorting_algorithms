#include "sort.h"

/**
  * selection_sort - function to sort an array using selection sort
  * @array: the array to sort
  * @size: the size of the array
  *
  * Return: void
  */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, idx;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}

		if (idx != i)
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
