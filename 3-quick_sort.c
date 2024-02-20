#include "sort.h"

/**
 * swap - swaps the values of two integers pointed to by given pointers
 * @x: pointer to the first integer
 * @y: pointer to the second integer
 *
 * Description: Takes two integer pointers, `idx_i` and `idx_j`, and swaps the
 * values pointed to by these pointers. This is achieved by using a temporary
 * variable to store the value of one pointer and then assigning the value of
 * the other pointer to it, and vice versa.
 *
 * Return: void (no return value)
 */

void swap(int *x, int *y)
{
	int temp = 0;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - partitions an array around a pivot element using the Hoare
 * partition scheme
 * @array: pointer to the unsorted array
 * @start: starting index of the subarray to partition
 * @pivot: index of the pivot element
 * @size: size of the array
 *
 * Description: Partitions the subarray `array[start:pivot-1]` around the pivot
 * element `array[pivot]`. Elements smaller than the pivot are placed before
 * it, and elements larger than the pivot are placed after it. The pivot
 * element remains in its original position. The function uses the Hoare
 * partition scheme, which places the pivot element in its final sorted
 * position at the end of the partition process.
 *
 * Return: The index of the pivot element after partitioning.
 */

int partition(int *array, size_t size, size_t start, size_t pivot)
{
	size_t idx_i;

	for (idx_i = start; idx_i < pivot; idx_i++)
	{
		if (array[idx_i] < array[pivot])
		{
			if (idx_i != start)
			{
				swap(&array[start], &array[idx_i]);
				print_array(array, size);
			}
			start++;
		}
	}
	if (array[start] > array[pivot])
	{
		swap(&array[start], &array[pivot]);
		pivot = start;
		print_array(array, size);
	}
	return (pivot);
}

/**
 * lquick - sorts a subarray of an integer array using the Lomuto
 * partition scheme
 * @array: pointer to the unsorted array
 * @size: size of the array
 * @start: starting index of the subarray to sort
 * @end: ending index of the subarray to sort
 *
 * Description: Sorts the subarray `array[start:end]` in ascending order using
 * the quicksort algorithm with the Lomuto partition scheme. The Lomuto
 * partition scheme places the pivot element at its final sorted position,
 * and elements smaller than the pivot are placed before it, while elements
 * greater than the pivot are placed after it. The function recursively
 * sorts the subarrays before and after the pivot.
 *
 * Return: void (no return value)
 */

void lquick(int *array, size_t size, size_t start, size_t end)
{
	size_t split;


	if (end == 0 || end <= start)
	{
		return;
	}
	split = partition(array, size, start, end);
	if (split != 0 && split >= start)
	{
		lquick(array, size, start, split - 1);
	}
	if (split < size - 1)
	{
		lquick(array, size, split + 1, end);
	}

}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quicksort algorithm
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order using the
 * quicksort algorithm with the Lomuto partition scheme. Quicksort works by
 * recursively partitioning the array around a pivot element. Elements smaller
 * than the pivot are placed before it, and elements larger than the pivot are
 * placed after it. This process continues until the entire array is sorted.
 *
 * Return: void (no return value)
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lquick(array, size, 0, size - 1);
}
