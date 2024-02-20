#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t idx_i;

	idx_i = 0;
	while (array && idx_i < size)
	{
		if (idx_i > 0)
			printf(", ");
		printf("%d", array[idx_i]);
		++idx_i;
	}
	printf("\n");
}
