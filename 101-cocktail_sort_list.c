#include "sort.h"

/**
 * swap_nodes - a function that swaps two nodes of doubly
 * linked list
 * @head: head of linked list
 * @node1: first node to swap
 * @node2: second node to swap
 *
 * Return: void
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL || *head == NULL)
		return;

	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*head = node2;
	}

	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev != NULL)
		node2->prev->next = node2;
}


/**
 * cocktail_sort_list - a function that sorts random numbers
 * using cocktail sort algorithm.
 * @list: pointer to head of the doubly linked list
 *
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped;
	listint_t *start;
	listint_t *end = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;
	start = *list;
	do {
		swapped = false;

		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = true;
				print_list(*list);
			}
			else
				start = start->next;
		}

		if (!swapped)
			break;
		swapped = false;
		end = start;
		start = start->prev;
		while (start != NULL)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = true;
				print_list(*list);
			}

			start = start->prev;
		}
		start = *list;
	} while (swapped);
}
