#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * enum kind_e - enumeration for the four card suits
 *
 * Description: Represents the different suits a card can belong to:
 * @SPADE: Spades suit
 * @HEART: Hearts suit
 * @CLUB: Clubs suit
 * @DIAMOND: Diamonds suit
 *
 * Note: `kind_e` is an integer enumeration starting from 0.
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 *
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
void kind_sort(deck_node_t **list);
void num_sort(deck_node_t **list);
int aux_num_fun(deck_node_t *head_tmp1);
void sort_deck(deck_node_t **deck);
#endif /* DECK_H */
