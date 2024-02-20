#include "sort.h"
void helper(int *array, int *temp, size_t lo, size_t hi);
void merge(int *a, int *temp, size_t llo, size_t lhi, size_t rlo, size_t rhi);
/**
 * merge_sort - sorts an array of integers in ascending order using the merge
 * sort algorithm
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order using the
 * merge sort algorithm. Merge sort is a divide-and-conquer algorithm that
 * repeatedly divides the array into halves, sorts the sub-arrays recursively,
 * and then merges them back together in sorted order.
 *
 * Return: void (no return value)
 */

void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	if (size > 1)
		helper(array, temp, 0, size - 1);
	free(temp);
}
/**
 * helper - recursively divides and merges sub-arrays for merge sort
 * @array: pointer to the array to be sorted
 * @temp: pointer to a temporary array for merging
 * @lo: low index of the sub-array to be sorted (inclusive)
 * @hi: high index of the sub-array to be sorted (inclusive)
 *
 * Description: Recursively implements the merge sort algorithm by dividing the
 * sub-array `[lo:hi]` into two halves, sorting them recursively, and then
 * merging them back together using the `merge` function.
 *
 * Return: void (no return value)
 */

void helper(int *array, int *temp, size_t lo, size_t hi)
{
	if (hi > lo)
	{
		helper(array, temp, lo, (lo + hi + 1) / 2 - 1);
		helper(array, temp, (lo + hi + 1) / 2, hi);
		merge(array, temp, lo, (lo + hi + 1) / 2 - 1,
		      (lo + hi + 1) / 2, hi);
	}
}
/**
 * merge - merges two sorted sub-arrays of an integer array
 * @a: pointer to the original array
 * @temp: pointer to a temporary array for merging
 * @llo: left sub-array low index (inclusive)
 * @lhi: left sub-array high index (inclusive)
 * @rlo: right sub-array low index (inclusive)
 * @rhi: right sub-array high index (inclusive)
 *
 * Description: Merges two sorted sub-arrays `[llo:lhi]` and `[rlo:rhi]` of the
 * array `a` into a single sorted sub-array using the merge sort algorithm.
 * The function uses a temporary array `temp` to store the merged elements.
 *
 * Return: void (no return value)
 */

void merge(int *a, int *temp, size_t llo, size_t lhi, size_t rlo, size_t rhi)
{
	size_t lhead = llo, lsize = lhi - llo + 1;
	size_t rhead = rlo, rsize = rhi - rlo + 1;
	size_t idx_i = llo;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(a + lhead, lsize);
	printf("[right]: ");
	print_array(a + rhead, rsize);
	while (llo <= lhi && rlo <= rhi)
	{
		if (a[llo] <= a[rlo])
			temp[idx_i++] = a[llo++];
		else
			temp[idx_i++] = a[rlo++];
	}
	while (llo <= lhi)
		temp[idx_i++] = a[llo++];
	while (rlo <= rhi)
		temp[idx_i++] = a[rlo++];
	for (idx_i = lhead; idx_i <= rhi; idx_i++)
		a[idx_i] = temp[idx_i];
	printf("[Done]: ");
	print_array(a + lhead, lsize + rsize);
}
