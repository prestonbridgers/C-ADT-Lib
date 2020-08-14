#ifndef H_INCLUDED_LINKEDLIST
#define H_INCLUDED_LINKEDLIST

typedef struct List{
	void *data;
	struct List *next;
}List;

int ll_print(List *list, void(*print_func)(void *));	/*Prints the contents of a list*/
int ll_add(List **list, void *filled_data);				/*Adds another node to the linked list*/
int ll_tail_get(List **tail, List *list);				/*Gets the tail node of a linked list*/
int ll_free(List *list);								/*Frees memory associated with a linked list*/
int ll_addEnd(List **list, void *filled_data);			/*Adds an element to the end of the list*/
int ll_remove(List **list, int(*remove_func)(void *, void *), void *target); /*Removes target from the list based on the remove_func's comparison*/

#endif
