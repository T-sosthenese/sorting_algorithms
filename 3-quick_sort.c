#include "sort.h"

/**
 * quick_sort - sorts an array in ascending order using quick sort algorithm
 *		with Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive function that performs the quick sort
 * @array: the array to be sorted
 * @low: The lower index of the partition
 * @high: the upper index of the partition
 */

void quicksort_recursive(int *array, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high);

		quicksort_recursive(array, low, pivot_idx - 1);
		quicksort_recursive(array, pivot_idx + 1, high);
	}
}

/**
 * partition - partitions the array and places the pivot in the correct pos
 * @array: The array to be partitioned
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 *
 * Return: Pivot index
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high + 1);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high + 1);
	}
	return (i + 1);
}
