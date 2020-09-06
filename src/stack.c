#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *stack_create()
{
	Stack *new_stack = calloc(1, sizeof *new_stack);
	new_stack->data = ll_create();
	new_stack->size = 0;

	return new_stack;
}

void stack_destroy(Stack *st)
{
	ll_destroy(st->data);
	free(st);
}

int stack_push(Stack *st, void *data)
{
	ll_add(st->data, data);
	st->size++;
	return 0;
}

void *stack_pop(Stack* st)
{
	if (st->size == 0)
		return NULL;

	ListNode *target_node = st->data->head->next;
	void *target_data = target_node->data;

	st->data->head->next = target_node->next;
	free(target_node);
	st->size--;
	return target_data;
}
