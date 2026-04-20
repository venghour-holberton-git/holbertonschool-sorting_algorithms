#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 *
 * Description: This function sorts the list by moving nodes
 * into their correct position in the already sorted portion.
 * Nodes are swapped by changing pointers, not values.
 * The list is printed after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;

		while (prev != NULL && current->n < prev->n)
		{

			prev->next = current->next;
			if (current->next != NULL)
			current->next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev != NULL)
			prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;

			prev = current->prev;

			print_list(*list);
		}

		current = next;
	}
}
