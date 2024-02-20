#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the insertion sort algorithm
 * @list: double pointer to the head of the list to be sorted
 *
 * Description: Sorts the elements of `list` in ascending order by iterating
 * through the list, selecting the current node, and comparing it to its
 * previous nodes. If the current node is smaller than the previous node, it is
 * inserted before that node, maintaining the sorted order.
 *
 * Return: void (no return value)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node = NULL, *p = NULL, *next_node = NULL,
	*prev_node = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	next_node = *list;
	for (curr_node = (*list)->next; next_node; curr_node = next_node)
	{
		next_node = curr_node->next;
		prev_node = curr_node;
		for (p = curr_node->prev; prev_node; p = prev_node)
		{
			prev_node = p->prev;
			if (curr_node->n < p->n)
			{
				curr_node->prev = p->prev;
				p->next = curr_node->next;
				if (p->prev)
					p->prev->next = curr_node;
				if (curr_node->next)
					curr_node->next->prev = p;
				p->prev = curr_node;
				curr_node->next = p;
				if (!curr_node->prev)
					*list = curr_node;
				print_list(*list);
			}
		}
	}
}
