#include "deck.h"
/**
 * aux_num_fun - calculates a numeric value for a card based on its value
 * @head_tmp1: pointer to a `deck_node_t` element
 *
 * Description: Returns an integer representing the numeric value of a card's
 * face value. It uses pre-defined arrays `num` and `val` to map character
 * values to numbers.
 *
 * Return: integer representing the card's numeric value
 */

int aux_num_fun(deck_node_t *head_tmp1)
{
	int aux_num, j;
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char val[13] = {'A', '2', '3', '4', '5', '6', '7',
					'8', '9', '1', 'J', 'Q', 'K'};

	for (j = 0; j < 13; j++)
	{
		if (head_tmp1->card->value[0] == val[j])
			aux_num = num[j];
	}

	return (aux_num);
}
/**
 * num_sort - sorts a singly linked list of cards by their number
 * @list: pointer to the head of the linked list
 *
 * Description: Sorts the linked list of `deck_node_t` elements pointed to
 * by `list` in ascending order based on the `number` member of the `card_t`
 * structure within each node. Uses a hybrid kind-then-number sort approach.
 *
 * Return: void (modifies the list in-place)
 */

void num_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag = 0, idx_i, aux_num1, aux_num2;
	size_t k;

	head_tmp1 = *list;
	head_tmp2 = *list;
	for (idx_i = 0; idx_i < 4; idx_i++)
	{ k =  head_tmp1->card->kind;
		while (head_tmp1->next && head_tmp1->next->card->kind == k)
		{
			aux_num1 = aux_num_fun(head_tmp1);
			aux_num2 = aux_num_fun(head_tmp1->next);
			flag = 0;
			head_tmp2 = head_tmp1;
			while (head_tmp2 && head_tmp2->card->kind == k && aux_num1 >
				aux_num2)
			{	aux1 = head_tmp2;
				aux2 = head_tmp2->next;
				aux1->next = aux2->next;
				if (aux2->next)
					aux2->next->prev = aux1;
				aux2->prev = aux1->prev;
				aux2->next = aux1;
				aux1->prev = aux2;
				if (aux2->prev)
					aux2->prev->next = aux2;
				head_tmp2 = aux2->prev;
				if (!aux2->prev)
					*list = aux2;
				flag = 1;
				if (!head_tmp2)
					break;
				aux_num1 = aux_num_fun(head_tmp2);
				aux_num2 = aux_num_fun(head_tmp2->next);
			}
			if (flag == 0)
				head_tmp1 = head_tmp1->next;
		}
		head_tmp1 = head_tmp1->next;
	}
}
/**
 * kind_sort - sorts a singly linked list of cards by their kind
 * @list: pointer to the head of the linked list
 *
 * Description: Sorts the linked list of `card_node_t` elements pointed to by
 * `list` in ascending order based on the `kind` member of the `card_t`
 * structure within each node. It uses a bubble sort algorithm with a single
 * pass through the list.
 *
 * Return: void (modifies the list in-place)
 */

void kind_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag;

	if (list)
	{
		head_tmp1 = *list;
		head_tmp2 = *list;
		while (list && head_tmp1->next)
		{
			if (head_tmp1->next)
			{
				flag = 0;
				head_tmp2 = head_tmp1;
				while (head_tmp2 && head_tmp2->card->kind >
					head_tmp2->next->card->kind)
				{
					aux1 = head_tmp2;
					aux2 = head_tmp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					head_tmp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					flag = 1;
				}
			}
			if (flag == 0)
				head_tmp1 = head_tmp1->next;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards by kind and then by number
 * @deck: pointer to the head of the linked list representing the deck
 *
 * Description: Sorts the linked list of `deck_node_t` elements pointed to by
 * `deck` in ascending order first by card kind using `kind_sort` and then by
 * card number within each kind group using `num_sort`.
 *
 * Return: void (modifies the deck list in-place)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}
