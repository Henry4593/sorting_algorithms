#include "sort.h"
size_t _max(int *array, size_t size);
int *setup_count_array(int *array, size_t size, size_t k);
/**
 * counting_sort - sorts an array of integers in ascending order using counting
 * sort
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order using the
 * counting sort algorithm. Counting sort works by first creating a count array
 * to store the frequency of each unique element in the original array. Then,
 * it uses the count array to place elements in their final sorted positions in
 * the original array. This algorithm performs well for arrays with a limited
 * range of values.
 *
 * Return: void (no return value)
 */

void counting_sort(int *array, size_t size)
{
	int *count_array = NULL, *temp = NULL;
	size_t idx_i, k;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	for (idx_i = 0; idx_i < size; idx_i++)
		temp[idx_i] = array[idx_i];
	k = _max(array, size);
	count_array = setup_count_array(array, size, k);
	for (idx_i = 0; idx_i < size; idx_i++)
		array[--count_array[temp[idx_i]]] = temp[idx_i];
	free(temp);
	free(count_array);
}
/**
 * setup_count_array - creates and initializes the count array for
 * counting sort.
 * @array: pointer to the original array
 * @size: size of the original array
 * @k: maximum value in the original array
 *
 * Description: Creates and initializes the count array used in the counting
 * sort algorithm. The count array stores the frequency of each unique element
 * in the original array, up to the maximum value `k`. It also calculates
 * cumulative counts to facilitate the sorting process.
 *
 * Return: pointer to the allocated and initialized count array
 */

int *setup_count_array(int *array, size_t size, size_t k)
{
	int *countArray = NULL;
	size_t idx_i;

	countArray = malloc(sizeof(int) * (k + 1));
	if (!countArray)
		return (NULL);
	for (idx_i = 0; idx_i < k + 1; idx_i++)
		countArray[idx_i] = 0;
	for (idx_i = 0; idx_i < size; idx_i++)
		countArray[array[idx_i]] += 1;
	for (idx_i = 0; idx_i < k; idx_i++)
		countArray[idx_i + 1] = countArray[idx_i] + countArray[idx_i + 1];
	print_array(countArray, k + 1);
	return (countArray);
}
/**
 * _max - finds the maximum element in an array of integers
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Iterates through the array `array` of size `size` and returns
 * the maximum element found.
 *
 * Return: the maximum element in the array
 */

size_t _max(int *array, size_t size)
{
	size_t idx_i;
	int max;

	max = array[0];
	for (idx_i = 0; idx_i < size; idx_i++)
	{
		if (array[idx_i] > max)
			max = array[idx_i];
	}
	return (max);
}
