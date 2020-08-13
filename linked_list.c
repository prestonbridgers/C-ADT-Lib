#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int ll_addEnd(List **list, void *filled_data)
{
	// The case that the list is currently empty
	if (*list == NULL)
	{
		*list = calloc(1, sizeof(List));
		(*list)->data = filled_data;
		(*list)->next = NULL;
	}
	else // The case that the list is not empty
	{
		List *tail = NULL;
		ll_tail_get(&tail, *list);

		List *new_tmp = calloc(1, sizeof(List));
		new_tmp->data = filled_data;
		new_tmp->next = NULL;
		tail->next = new_tmp;
	}

	return 0;
}

int ll_free(List *list)
{
	if (list == NULL)
		return 1;

	List *tmp;

	for (; list != NULL;)
	{
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
	return 0;
}

int ll_tail_get(List **tail, List *list)
{
	if (list == NULL)
		return 1;

	for (;; list = list->next)
	{
		if (list->next == NULL)
		{
			*tail = list;
			break;
		}
	}

	return 0;
}

/*
 * Function to iterate througha give linked list of people and print
 *   format strings for each entry.
*/
int ll_print(List *list, void(*print_func)(void *))
{
	if (list == NULL)
	{
		fprintf(stderr, "in people_print: list is null, returning\n");
		return 1;
	}

	for (List *iterator = list; iterator != NULL; iterator = iterator->next)
	{
		print_func(iterator->data);
	}
}

/* 
 * Function to add people to a given linked list of people.
 * Adds people to the "front" of the list as opposed to the "tail".
 * This results in a order of elements similar to a stack data structure.
 * I.E. The elements of this list will be printed in reverse order that
 *   they were added.
*/
int ll_add(List **list, void *filled_data)
{
	// The case that the list is currently empty
	if (*list == NULL)
	{
		*list = calloc(1, sizeof(List));
		(*list)->data = filled_data;
		(*list)->next = NULL;
	}
	else // The case that the list is not empty
	{
		List *new_tmp = calloc(1, sizeof(List));
		new_tmp->data = filled_data;
		new_tmp->next = *list;
		*list = new_tmp;
	}

	return 0;
}
