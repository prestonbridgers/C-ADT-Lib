#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "linked_list.h"

typedef struct
{
	int size;
	List *data;
} Stack;

Stack* stack_create();
void   stack_destroy(Stack *st);
int    stack_push(Stack *st, void *data);
void*  stack_pop(Stack *st);

#endif
