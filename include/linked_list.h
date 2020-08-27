#ifndef H_INCLUDED_LINKEDLIST
#define H_INCLUDED_LINKEDLIST

typedef struct List{
	void *data;
	struct List *next;
}List;

/*Prints the contents of a list*/
int ll_print(List *list, void(*print_func)(void *));

/*Adds another node to the linked list*/
int ll_add(List **list, void *filled_data);

/*Returns target from the list if it exists*/
void *ll_get(List *list, int(*cmpr_func)(void *, void *), void *target);

/*Gets the tail node of a linked list*/
int ll_tail_get(List **tail, List *list);

/*Frees memory associated with a linked list*/
int ll_free(List *list);

/*Adds an element to the end of the list*/
int ll_addEnd(List **list, void *filled_data);

/*Removes target from the list based on the remove_func's comparison*/
int ll_remove(List **list, int(*cmpr_func)(void *, void *), void *target); 
#endif
