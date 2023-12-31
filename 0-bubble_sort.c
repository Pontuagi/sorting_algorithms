#include "sort.h"

/**
 * bubble_sort - algorithm to sort an array in ascending order
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size -  1; i++)
	{
		for (j = 0; j + 1 < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}

	}
}
