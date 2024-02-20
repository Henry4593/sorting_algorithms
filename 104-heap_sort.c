#include "sort.h"
/**
 * check_tree - maintains the max-heap property for a subtree in an array
 * @array: the array representing the heap
 * @size_init: the initial size of the array before sorting
 * @size: the current size of the subtree being checked
 * @idx_i: the index of the parent node in the subtree
 *
 * Description: Checks and fixes the max-heap property for the subtree rooted
 * at index `idx_i` in the array. Assumes the subtree has `size` elements and
 * was built from an initially larger array of size `size_init`. Uses
 * `print_array` for visualization.
 *
 * Return: void (modifies the array in-place)
 */

void check_tree(int *array, size_t size_init, size_t size, size_t idx_i)
{

	int n, branch1, branch2;
	size_t br1, br2;

	br1 = idx_i * 2 + 1;
	br2 = br1 + 1;
	branch1 = array[br1];
	branch2 = array[br2];
	if (((br1 < size) && (br2 < size) &&
		(branch1 >= branch2 && branch1 > array[idx_i]))
		|| ((br1 == size - 1) && branch1 > array[idx_i]))
	{
		n = array[idx_i];
		array[idx_i] = branch1;
		array[br1] = n;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(branch2 > branch1 && branch2 > array[idx_i]))
	{
		n = array[idx_i];
		array[idx_i] = branch2;
		array[br2] = n;
		print_array(array, size_init);
	}
	if (br1 < size - 1)
		check_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		check_tree(array, size_init, size, br2);
}
/**
 * heap_sort - sorts an array of integers in ascending order using heap sort
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Description: Sorts the array `array` of integers in ascending order using
 * the heap sort algorithm. Builds a max-heap from the array, iteratively
 * extracts the maximum element (now at the root), and places it at the end of
 * the sorted portion of the array. Assumes `check_tree` and `print_array` are
 * defined elsewhere.
 *
 * Return: void (modifies the array in-place)
 */

void heap_sort(int *array, size_t size)
{
	size_t idx, size_init = size;
	int n;

	if (!array)
		return;
	for (idx = 0; idx < size / 2 ; idx++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - idx);
	}
	for (idx = 0; idx < size_init - 1; idx++)
	{
		n = array[0];
		array[0] = array[size - 1 - idx];
		array[size - 1 - idx] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - idx - 1, 0);
	}

}
