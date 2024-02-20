#include "sort.h"
void heaplify(int *array, size_t size, size_t cur_idx, size_t s);
void siftdown(int *array, size_t size, size_t heap_size, size_t root);
void swap(int *array, size_t size, size_t e1, size_t e2);
/**
 * heap_sort - sorts an array of integers in ascending order using the heap
 * sort algorithm.
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order using the heap
 * sort algorithm. Heap sort builds a max-heap from the input array, repeatedly
 * swaps the root element with the last element of the heap (reducing the heap
 * size), and sifts down the swapped element to maintain the max-heap property.
 * This process ensures that the largest element is placed at the end of the
 * sorted array in each iteration.
 *
 * Return: void (no return value, modifies the array in-place)
 */

void heap_sort(int *array, size_t size)
{
	size_t heap_size = size;

	if (!array || size < 2)
		return;
	heaplify(array, size, 0, size);
	while (heap_size > 1)
	{
		swap(array, size, 0, heap_size - 1);
		heap_size--;
		siftdown(array, size, heap_size, 0);
	}
}

/**
 * heaplify - converts a sub-array into a max-heap starting from a given index
 * @array: pointer to the array representing the heap
 * @size: size of the array
 * @cur_idx: index from which to start heapifying
 * @s: (unused) argument, can be ignored
 *
 * Description: Converts the sub-array `array[cur_idx:size-1]` into a max-heap
 * using the siftdown algorithm. This function starts at the parent of the last
 * element in the sub-array and sifts down each element to its correct position
 * in the max-heap. The `s` argument is unused and can be ignored.
 *
 * Return: void (modifies the array in-place)
 */

void heaplify(int *array, size_t size, size_t cur_idx, size_t s)
{
	size_t idx_i;
	(void) s;

	for (idx_i = (size - 2) / 2; idx_i >= cur_idx; idx_i--)
	{
		siftdown(array, size, size - 1, idx_i);
		if (idx_i == 0)
			break;
	}
}

/**
 * siftdown - maintains the max-heap property of a sub-tree
 * @array: pointer to the array representing the heap
 * @size: size of the array
 * @heap_size: current size of the heap (sub-array of the array)
 * @root: index of the root node of the sub-tree
 *
 * Description: Maintains the max-heap property of a sub-tree rooted at index
 * `root` in the array `array`. This function assumes that the left and right
 * sub-trees of `root` are already max-heaps. It compares `root` with its
 * children and swaps it with the larger child if necessary, recursively
 * sifting down the larger child until the max-heap property is restored.
 *
 * Return: void (no return value, modifies the array in-place)
 */

void siftdown(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t target = root;
	size_t left, right;

	left = root * 2 + 1;
	right = root * 2 + 2;
	while (left < heap_size || right < heap_size)
	{
		if (left < heap_size && array[root] < array[left])
			target = left;
		if (right < heap_size && array[target] < array[right])
			target = right;
		if (target != root)
			swap(array, size, root, target);
		else
			break;
		root = target;
		left = root * 2 + 1;
		right = root * 2 + 2;
	}
}
/**
 * swap - swaps two elements in an array
 * @array: pointer to the array
 * @size: size of the array
 * @e1: index of the first element to swap
 * @e2: index of the second element to swap
 *
 * Description: Swaps the elements at indices `e1` and `e2` in the array
 * `array`. Assumes `e1` and `e2` are within the bounds of the array
 * (0 to `size-1`).
 *
 * Return: void (no return value)
 */

void swap(int *array, size_t size, size_t e1, size_t e2)
{
	int temp;

	temp = array[e1];
	array[e1] = array[e2];
	array[e2] = temp;
	print_array(array, size);
}
