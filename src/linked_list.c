#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "linked_list.h"

/*
 * Creates a new node and adds it to the end of the list.
*/
int ll_addEnd(List **list, void *filled_data)
{
	// The case that the list is currently empty
	if (*list == NULL)
	{
		*list = calloc(1, sizeof(List));
		(*list)->data = filled_data;
		(*list)->next = NULL;
	}
	// The case that the list is not empty
	else
	{
		List *tail = NULL;
		ll_tail_get(&tail, *list);

		List *new_tmp = calloc(1, sizeof(List));
		new_tmp->data = filled_data;
		new_tmp->next = NULL; tail->next = new_tmp;
	}

	return 0;
}

/*
 * Searches for and returns a pointer to target element
 *   if it's in the list.
*/
void *ll_get(List *list, int(*cmpr_func)(void *, void *), void *target)
{
	List *iter = list;

	for(;; iter = iter->next)
	{
		if(iter == NULL)
			break;

		if (cmpr_func(iter->data, target) == 0)
		{
			return iter->data;
			break;
		}
	}

	return NULL;
}

/*
 * Frees all memory associated with the linked list.
*/
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

/*
 * Finds and returns the tail of the list.
*/
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

	return 0;
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
	// The case that the list is not empty
	else
	{
		List *new_tmp = calloc(1, sizeof(List));
		new_tmp->data = filled_data;
		new_tmp->next = *list;
		*list = new_tmp;
	}

	return 0;
}

/*
 * Searches for the target element in the list using cmpr_func
 *   and removes it.
*/
int ll_remove(List **list, int(*cmpr_func)(void *, void *), void *target)
{
	List *prev = NULL;
	List *iter = *list;
	uint8_t is_found_target = 0;

	while(!is_found_target)
	{
		if(iter == NULL)
			is_found_target = 1;

		// If the target is found
		if (cmpr_func(iter->data, target) == 0)
		{
			// The case that the target is at the beginning
			if (prev == NULL)
			{
				List *tmp = *list;
				*list = (*list)->next;
				free(tmp->data);
				free(tmp);
			}
			// All other cases
			else
			{
				prev->next = iter->next;
				free(iter->data);
				free(iter);
			}

			
			is_found_target = 1;
		}
		else
		{
			prev = iter;
			iter = iter->next;
		}
	}

	return 0;
}
