#include "sort.h"
size_t gap(size_t size);
void sort_sublist(int *array, size_t gap, size_t size, size_t lo);
/**
 * shell_sort - sorts an array of integers in ascending order using the shell
 * sort algorithm
 * @array: pointer to the unsorted array
 * @size: size of the array
 *
 * Description: Sorts the elements of `array` in ascending order using the
 * shell sort algorithm. Shell sort is a divide-and-conquer sorting algorithm
 * that iterates through the array, comparing elements with a gap between them.
 * The gap starts large and gradually decreases, allowing for larger
 * comparisons and efficient sorting. This process continues until the gap is
 * 1, resulting in a sorted array.
 *
 * Return: void (no return value)
 */

void shell_sort(int *array, size_t size)
{
	size_t gaps, low;

	if (!array || size < 2)
		return;
	gaps = gap(size);
	while (gaps > 0)
	{
		for (low = 0; low < gaps; low++)
			sort_sublist(array, gaps, size, low);
		print_array(array, size);
		gaps = (gaps - 1) / 3;
	}

}

/**
 * sort_sublist - sorts a sub-list of an integer array using insertion sort
 * @array: pointer to the unsorted array
 * @gap: the gap between elements to compare
 * @size: size of the sub-list
 * @lo: starting index of the sub-list
 *
 * Description: Sorts the sub-list `array[lo:size-1]` with a gap of `gap`
 * between elements compared. The function uses the insertion sort algorithm,
 * where each element is inserted into its rightful position among its
 * predecessors with the specified gap. The function iterates through the
 * sub-list, comparing each element with its previous elements at intervals of
 *  `gap`, and swaps them if they are in the wrong order.
 *
 * Return: void (no return value)
 */

void sort_sublist(int *array, size_t gap, size_t size, size_t lo)
{
	size_t p, next_cand, next_p;
	int temp;
	size_t curr_node;

	for (curr_node = gap + lo; curr_node < size; curr_node = next_cand)
	{

		next_cand = curr_node + gap;

		for (p = curr_node - gap; p >= lo; p = next_p)
		{
			next_p = p - gap;
			printf("%d < %d?\n", array[curr_node], array[p]);
			if (array[curr_node] < array[p])
			{
				printf("swap\n");
				temp = array[p];
				array[p] = array[curr_node];
				array[curr_node] = temp;
				curr_node = p;
			}
			if (gap > p)
				break;
		}
	}
}

/**
 * gap - calculates the initial gap value for shell sort using the Knuth
 * sequence
 * @size: size of the array to be sorted
 *
 * Description: Calculates the initial gap value used in the shell sort
 * algorithm. The function follows the Knuth sequence, which recursively
 * defines gaps as 3n + 1, where n is a positive integer. The largest gap that
 * is less than or equal to the array size is chosen as the initial gap.
 *
 * Return: The initial gap value (size_t)
 */

size_t gap(size_t size)
{
	size_t n = 1;

	while (n <= size)
		n = n * 3 - 1;
	return ((n - 1) / 3);
}
