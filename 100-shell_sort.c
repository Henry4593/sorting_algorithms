#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using shell sort
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Description: Sorts the array `array` of integers in ascending order using
 * the Shell sort algorithm. Uses the Knuth sequence for gap values,
 * iteratively performing insertion sort within subarrays defined by the gaps.
 *
 * Return: void (modifies the array in-place)
 */

void shell_sort(int *array, size_t size)
{
	size_t kunth[1000], k = 0, idx_j = 0, idx_i;
	int n, j2;

	if (!array)
		return;
	while (idx_j * 3 + 1 < size)
	{
		kunth[k] = idx_j * 3 + 1;
		idx_j = kunth[k++];
	}
	for (idx_i = 0; idx_i < k; idx_i++)
	{
		for (idx_j = 0; idx_j < size; idx_j++)
		{
			if ((idx_j + kunth[k - idx_i - 1]) > size - 1)
				break;
			j2 = idx_j;
			while (array[j2] > array[j2 + kunth[k - idx_i - 1]])
			{
				n = array[j2];
				array[j2] =  array[j2 + kunth[k - idx_i - 1]];
				array[j2 + kunth[k - idx_i - 1]] = n;
				j2 = j2 - kunth[k - idx_i - 1];
				if (j2 < 0)
					break;
			}
		}
		print_array(array, size);
	}
}
