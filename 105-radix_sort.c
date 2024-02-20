#include "sort.h"
size_t _max(int *array, size_t size, int ex);
int *setup_count_array(int *array, size_t size, size_t k, int ex);
void _counting_sort(int *array, size_t size, int ex);
/**
 * radix_sort - sorts an array of integers in ascending order using the radix
 * sort algorithm
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order using the
 * radix sort algorithm. Radix sort sorts numbers digit by digit, starting from
 * the least significant digit. It uses counting sort as a subroutine to sort
 * the elements based on each digit.
 *
 * Return: void (no return value, modifies the array in-place)
 */

void radix_sort(int *array, size_t size)
{
	int max_num, max_ex, n;
	size_t idx_i;

	if (!array || size < 2)
		return;
	for (idx_i = 0, max_num = array[0]; idx_i < size; idx_i++)
		if (array[idx_i] > max_num)
			max_num = array[idx_i];
	for (n = max_num, max_ex = 0; n >= 10; max_ex++)
		n /= 10;
	for (n = 0; n <= max_ex; n++, print_array(array, size))
		_counting_sort(array, size, n);
}
/**
 * _counting_sort - sorts an array of integers in ascending order using
 * counting sort.
 * @array: pointer to the unsorted array
 * @size: size of the array
 * @ex: digit position (0 for least significant, increasing towards most
 * significant)
 *
 * Description: Sorts the elements of `array` in ascending order based on the
 * digit at the specified `ex` position (starting from 0 for the least
 * significant digit). Uses counting sort, which creates a count array to store
 * the frequency of each digit value at the specified position. Then, it uses
 * the count array to place elements back into the original array in sorted
 * order.
 *
 * Return: void (modifies the array in-place)
 */

void _counting_sort(int *array, size_t size, int ex)
{
	int *count_array = NULL, *temp = NULL;
	size_t idx_i, k, factor;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	for (idx_i = 0; idx_i < size; idx_i++)
		temp[idx_i] = array[idx_i];
	k = _max(array, size, ex);
	count_array = setup_count_array(array, size, k, ex);
	for (factor = 1; ex > 0; factor *= 10, ex--)
		;
	for (idx_i = size; idx_i > 0; idx_i--)
		array[--count_array[temp[idx_i - 1] / factor % 10]] = temp[idx_i - 1];
	free(temp);
	free(count_array);
}
/**
 * setup_count_array - initializes a count array for counting sort
 * @array: pointer to the unsorted array
 * @size: size of the array
 * @k: maximum value considering the digit position (ex)
 * @ex: digit position (0 for least significant, increasing towards most
 * significant)
 *
 * Description: Allocates and initializes a count array for counting sort based
 * on the specified digit position `ex`. The count array will have `k + 1`
 * elements to store the frequencies of digit values at that position. It
 * iterates through the `array` and increments the corresponding element in the
 * `count_array` for each digit encountered. Finally, it calculates the
 * cumulative sum of frequencies (adjusted for indices) to be used for placing
 * elements back into the original array.
 *
 * Return: pointer to the allocated count array, or NULL on allocation failure
 */

int *setup_count_array(int *array, size_t size, size_t k, int ex)
{
	int *countArray = NULL;
	size_t idx_i;
	int d = 0, factor = 1, idx_j;

	countArray = malloc(sizeof(int) * (k + 1));
	if (!countArray)
		return (NULL);
	for (idx_j = 0; idx_j < ex; factor *= 10, idx_j++)
		;
	for (idx_i = 0; idx_i < k + 1; idx_i++)
		countArray[idx_i] = 0;
	for (idx_i = 0, d = 0; idx_i < size; idx_i++, d = 0)
	{
		if (array[idx_i] >= factor)
			d = array[idx_i] / factor % 10;
		countArray[d] += 1;
	}
	for (idx_i = 0; idx_i < k; idx_i++)
		countArray[idx_i + 1] = countArray[idx_i] + countArray[idx_i + 1];
	return (countArray);
}
/**
 * _max - finds the maximum value considering a specific digit position
 * @array: pointer to the unsorted array
 * @size: size of the array
 * @ex: digit position (0 for least significant, increasing towards most
 * significant)
 *
 * Description: Finds the maximum value in the `array` considering the digit at
 * the specified `ex` position (starting from 0 for the least significant
 * digit). It ignores digits beyond the specified position.
 *
 * Return: the maximum digit value at the specified position
 */

size_t _max(int *array, size_t size, int ex)
{
	size_t idx_i, max, factor;

	for (factor = 1; ex > 0; factor *= 10, ex--)
		;
	max = array[0] / factor % 10;
	for (idx_i = 0; idx_i < size; idx_i++)
	{
		if (array[idx_i] / factor % 10 > max)
			max = array[idx_i] / factor % 10;
	}
	return (max);
}
