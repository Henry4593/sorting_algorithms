#include "sort.h"
#define up 1
#define down 0
void bs_helper(int *array, size_t size, size_t subsize, size_t idx, int dir);
void bs_merge(int *array, size_t size, size_t subsize, size_t idx, int dir);
void cmpswap(int *array, size_t idx_i, size_t idx_j, int dir);
/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * bitonic sort algorithm
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order using the
 * bitonic sort algorithm. This is a recursive divide-and-conquer algorithm
 * that recursively sorts smaller sub-arrays and merges them in a specific
 * order (bitonic sequences) to achieve overall sorting.
 *
 * Return: void (modifies the array in-place)
 */

void bitonic_sort(int *array, size_t size)
{
	bs_helper(array, size, size, 0, up);
}
/**
 * bs_helper - recursive helper function for bitonic sort
 * @array: pointer to the array being sorted
 * @size: total size of the array
 * @subsize: size of the current sub-array being processed
 * @idx: index of the first element in the current sub-array
 * @dir: direction of sorting (up or down)
 *
 * Description: Recursively sorts sub-arrays and merges them in a bitonic
 * sequence to achieve overall sorting. It divides the sub-array into two
 * halves, recursively sorts them in opposite directions, and then merges them
 * using `bs_merge`.
 *
 * Return: void (modifies the array in-place)
 */

void bs_helper(int *array, size_t size, size_t subsize, size_t idx, int dir)
{
	size_t sub = subsize / 2;

	if (subsize > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n",
		       subsize, size, dir ? "UP" : "DOWN");
		print_array(array + idx, subsize);
		bs_helper(array, size, sub, idx, up);
		bs_helper(array, size, sub, idx + sub, down);
		bs_merge(array, size, subsize, idx, dir);
	}
}
/**
 * bs_merge - merges two bitonic sub-arrays in a specified direction
 * @array: pointer to the array being sorted
 * @size: total size of the array
 * @subsize: size of the sub-arrays to be merged
 * @idx: index of the first element in the sub-arrays
 * @dir: direction of merging (up or down)
 *
 * Description: Merges two adjacent bitonic sub-arrays of size `subsize` in the
 * specified `dir`ection (ascending or descending) using a sequence of
 * compare-and-swap operations.
 *
 * Return: void (modifies the array in-place)
 */

void bs_merge(int *array, size_t size, size_t subsize, size_t idx, int dir)
{
	size_t gap, idx_i;

	for (gap = subsize / 2; gap > 0; gap--)
		for (idx_i = idx; idx_i < subsize - gap + idx; idx_i++)
			cmpswap(array, idx_i, idx_i + gap, dir);
	printf("Result [%lu/%lu] (%s):\n",
	       subsize, size, dir == up ? "UP" : "DOWN");
	print_array(array + idx, subsize);
}
/**
 * cmpswap - compares and swaps two elements in an array if necessary
 * @array: pointer to the array
 * @idx_i: index of the first element
 * @idx_j: index of the second element
 * @dir: direction of sorting (up or down)
 *
 * Description: Compares the elements at `idx_i` and `idx_j` in the `array` and
 * swaps them if they are in the wrong order based on the specified `dir`ection
 * (ascending or descending).
 *
 * Return: void (modifies the array in-place)
 */

void cmpswap(int *array, size_t idx_i, size_t idx_j, int dir)
{
	int temp;

	if (dir == (array[idx_i] > array[idx_j] ? 1 : 0))
	{
		temp = array[idx_i];
		array[idx_i] = array[idx_j];
		array[idx_j] = temp;
	}
}
