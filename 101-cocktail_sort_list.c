#include "sort.h"
void swap(listint_t **list, listint_t *p1, listint_t *p2);
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the cocktail sort algorithm
 * @list: double pointer to the head of the list to be sorted
 *
 * Description: Sorts the elements of `list` in ascending order using the
 * cocktail sort algorithm. Cocktail sort is a variation of bubble sort that
 * iterates through the list in both directions, alternately comparing elements
 * from left to right and right to left. It continues iterating until no swaps
 * occur in a full pass, indicating the list is sorted.
 *
 * Return: void (no return value)
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *h = NULL, *t = NULL, *p = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	for (p = *list, h = *list; swapped; h = h->next, p = h)
	{
		swapped = 0;
		while (p->next && p != t)
		{
			if (p->n > p->next->n)
			{
				if (p == h)
					h = p->next;
				if (p->next == t)
					t = p;
				swap(list, p, p->next);
				swapped = 1;
				p = p->prev;
			}
			p = p->next;
		}
		t = p->prev;
		p = t;
		while (p->prev && p != h)
		{
			if (p->n < p->prev->n)
			{
				if (p == t)
					t = p->prev;
				if (p->prev == h)
					h = p;
				swap(list, p->prev, p);
				swapped = 1;
				p = p->next;
			}
			p = p->prev;
		}
	}
}

/**
 * swap - swaps the positions of two nodes in a doubly linked list
 * @list: double pointer to the head of the list
 * @p1: pointer to the first node
 * @p2: pointer to the second node
 *
 * Description: Swaps the positions of nodes `p1` and `p2` in the doubly linked
 * list pointed to by `list`. This involves updating the `prev` and `next`
 * pointers of both nodes, as well as the relevant pointers of their
 * neighboring nodes. The function also updates the `head` pointer of the list
 * if necessary.
 *
 * Return: void (no return value)
 */

void swap(listint_t **list, listint_t *p1, listint_t *p2)
{

	p2->prev = p1->prev;
	p1->next = p2->next;
	if (p1->prev)
		p1->prev->next = p2;
	if (p2->next)
		p2->next->prev = p1;
	p1->prev = p2;
	p2->next = p1;
	if (!p2->prev)
		*list = p2;
	print_list((const listint_t *) *list);
}
