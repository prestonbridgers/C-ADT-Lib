#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "linked_list.h"

/*
 * Creates and returns a pointer to a List.
*/
List *ll_create()
{
	List *new_list;
	ListNode *new_head;
	ListNode *new_tail;

	new_list = calloc(1, sizeof *new_list);
	new_head = calloc(1, sizeof *new_head);
	new_tail = calloc(1, sizeof *new_tail);

	new_head->data = NULL;
	new_head->next = new_tail;

	new_tail->data = NULL;
	new_tail->next = new_tail;

	new_list->head = new_head;
	new_list->tail = new_tail;

	return new_list;
}	

/*
 * Frees all memory associated with the linked list.
*/
int ll_destroy(List *list)
{
	if (list == NULL)
		return 1;

	ListNode *tmp;
	ListNode *traverser;

	traverser = list->head->next;
	while (traverser != list->tail)
	{
		tmp = traverser;
		traverser = traverser->next;
		free(tmp);
	}
	
	free(list->head);
	free(list->tail);
	free(list);
	return 0;
}

/*
 * Creates a new node and adds it to the end of the list.
*/
int ll_add(List *list, void *filled_data)
{
	// The list is never empty thanks to the head dummy node.
	ListNode *new_tmp = calloc(1, sizeof *new_tmp);
	new_tmp->data = filled_data;
	new_tmp->next = list->head->next;
	list->head->next = new_tmp;

	return 0;
}

/*
 * Searches for the target element in the list using cmpr_func
 *   and removes it.
*/
int ll_remove(List *list, int(*cmpr_func)(void *, void *), void *target)
{
	ListNode *iter = list->head;

	while (cmpr_func(iter->next->data, target) != 0)
		iter = iter->next;

	ListNode *tmp = iter->next;
	iter->next = iter->next->next;
	free(tmp);

	return 0;
}

/*
 * Searches for and returns a pointer to target element
 *   if it's in the list.
*/
void *ll_get(List *list, int(*cmpr_func)(void *, void *), void *target)
{
	ListNode *iter = list->head->next;

	while (cmpr_func(iter->data, target) != 0)
		iter = iter->next;
	
	return iter->data;
}

/*
 * Function to iterate througha give linked list of people and print
 *   format strings for each entry.
*/
int ll_print(List *list, void(*print_func)(void *))
{
	ListNode *traverser;

	for (traverser = list->head->next; traverser != list->tail; traverser = traverser->next)
		print_func(traverser->data);

	return 0;
}

