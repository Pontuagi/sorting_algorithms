#include "sort.h"
/**
 * counting_sort - function that sorts integers in ascending order
 * using counting sort algorithm
 * @array: pointer to array of integers to sort.
 * @size: size of array
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count, *sorted;
	size_t j;

	if (array == NULL || size <= 1)
		return;
	max = array[0];
	for (j = 1; j < size; j++)
		if (array[j] > max)
			max = array[j];
	count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]]++;
	for (i = 0; i <= max; i++)
		printf("%d ", count[i]);
	printf("\n");

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	sorted = (int *)malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = sorted[j];

	free(count);
	free(sorted);
}
