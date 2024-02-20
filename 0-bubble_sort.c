#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the bubble
 * sort algorithm
 *
 * @array: unsorted array of integers to be sorted
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order by repeatedly
 * iterating through the array and comparing adjacent elements. If elements are
 * in the wrong order, they are swapped. This process continues until no more
 * swaps are necessary, signifying a sorted array.
 *
 * Return: void (no return value)
 */

void bubble_sort(int *array, size_t size)
{
	size_t idx_i, idx_j, temp;

	if (!array)
		return;
	for (idx_i = 0; idx_i < size - 1; idx_i++)
	{
		for (idx_j = 0; idx_j < size - idx_i - 1; idx_j++)
		{
			if (array[idx_j] > array[idx_j + 1])
			{
				temp = array[idx_j];
				array[idx_j] = array[idx_j + 1];
				array[idx_j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
