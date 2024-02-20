#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection Sort algorithm
 * @array: pointer to the unsorted array of integers
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order by repeatedly
 * finding the minimum element in the unsorted portion of the array and
 * swapping it with the first element of the unsorted portion. This process
 * continues until the entire array is sorted.
 *
 * Return: void (no return value)
 */

void selection_sort(int *array, size_t size)
{
	size_t idx_i, idx_j, temp, min_idx;

	if (!array)
		return;
	for (idx_i = 0; idx_i < size - 1; idx_i++)
	{
		min_idx = idx_i;
		for (idx_j = idx_i + 1; idx_j < size; idx_j++)
		{
			if (array[min_idx] > array[idx_j])
				min_idx = idx_j;
		}
		if (min_idx != idx_i)
		{
			temp = array[idx_i];
			array[idx_i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
