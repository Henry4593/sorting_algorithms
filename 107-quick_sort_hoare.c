#include "sort.h"
void swap(int *array, int idx_i, int idx_j, size_t size);
void h_helper(int *array, size_t size, int lo, int hi);
int h_partition(int *array, size_t size, int lo, int hi);
/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Hoare partition scheme of the quick sort algorithm
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Implements the Hoare partition scheme of the quick sort
 * algorithm to sort the elements of `array` in ascending order. It recursively
 * partitions the array around a chosen pivot element, placing elements
 * smaller than the pivot before it and elements larger than the pivot after
 * it.This process continues on the sub-arrays until the entire array
 *is sorted.
 *
 * Return: void (modifies the array in-place)
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	h_helper(array, size, 0, size - 1);
}
/**
 * h_helper - recursive helper function for quick sort (Hoare partition scheme)
 * @array: pointer to the unsorted array
 * @size: size of the array
 * @lo: lower index of the current sub-array
 * @hi: upper index of the current sub-array
 *
 * Description: Recursively partitions and sorts the sub-array between `lo` and
 * `hi` using the Hoare partition scheme.It chooses a pivot element, partitions
 * the array such that elements smaller than the pivot are placed before it and
 * elements larger than the pivot are placed after it, and then recursively
 * sorts the resulting sub-arrays.
 *
 * Return: void (modifies the array in-place)
 */

void h_helper(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = h_partition(array, size, lo, hi);
		if (p > lo)
			h_helper(array, size, lo, p);
		h_helper(array, size, p + 1, hi);
	}
}
/**
 * h_partition - partitions a sub-array using the Hoare partition scheme
 * @array: pointer to the unsorted array
 * @size: size of the array
 * @lo: lower index of the sub-array
 * @hi: upper index of the sub-array
 *
 * Description: Partitions the sub-array between `lo` and `hi` using the Hoare
 * partition scheme. It chooses the last element `hi` as the pivot, places
 * elements smaller than the pivot before it and elements larger than the pivot
 * after it, and returns the final index of the pivot element.
 *
 * Return: final index of the pivot element (modifies the array in-place)
 */

int h_partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	/*int l = lo - 1, r = hi + 1;*/
	int l = lo, r = hi;

	while (1)
	{
		while (array[l] < pivot)
			l++;
		while (array[r] > pivot)
			r--;

		if (l < r)
			swap(array, l++, r--, size);
		else
		{
			if (l != r)
				return (r);
			return (r - 1);
		}
	}
}
/**
 * swap - swaps two elements in an array
 * @array: pointer to the array
 * @idx_i: index of the first element
 * @idx_j: index of the second element
 * @size: size of the array (for array bounds checking)
 *
 * Description: Swaps the elements at indices `idx_i` and `idx_j` in the
 * `array`. It uses a temporary variable to facilitate the exchange.
 * Additionally, it prints the array after swapping (optional).
 *
 * Return: void (modifies the array in-place)
 */

void swap(int *array, int idx_i, int idx_j, size_t size)
{
	int temp;

	temp = array[idx_i];
	array[idx_i] = array[idx_j];
	array[idx_j] = temp;
	print_array(array, size);
}
