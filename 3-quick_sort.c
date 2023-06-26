#include "sort.h"

/**
 * partition - partitions the array by selecting the last element as pivot
 * @array: an unsorted array
 * @low: lowest index of partition to be sort
 * @high: highest index of partition to be sorted
 * @size: size of the unsorted array
 *
 * Return: index of the partitioned element
 */

int partition(int *array, int low, int high, size_t size)
{
	int swap, pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts partitions of the integer array
 * @array: array to be sorted
 * @low: lowest index of the partition to be sorted
 * @high: highest index of the partition to sort
 * @size: size of the array
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using quick sort algo
 * @array: unsorted array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
