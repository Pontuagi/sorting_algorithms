#include "sort.h"

/**
  * insertion_sort_list - sort a doubly linked list using insertion sort
  * @list: the doubly linked list
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			temp->next = prev;
			prev->prev = temp;

			print_list(*list);
			prev = temp->prev;
		}

		current = current->next;
	}
}
