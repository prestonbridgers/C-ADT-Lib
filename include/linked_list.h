#ifndef H_INCLUDED_LINKEDLIST
#define H_INCLUDED_LINKEDLIST

/*List Node Struct*/
typedef struct ListNode{
	void *data;				// The data being stored in the node.
	struct ListNode *next;	// The pointer to the next node.
}ListNode;

/*List Struct*/
typedef struct List{
	int size;				// Store the # of elements in the list.
	struct ListNode *head;	// Dummy node book-ending the beginning.
	struct ListNode *tail;	// Dummy node book-ending the end.
}List;


/*Creates and returns a pointer to a List*/
List *ll_create();

/*Frees memory associated with a linked list*/
int ll_destroy(List *list);

/*Adds node to the linked list*/
int ll_add(List *list, void *filled_data);

/*Removes target from the list based on the remove_func's comparison*/
int ll_remove(List *list, int(*cmpr_func)(void *, void *), void *target); 

/*Returns target from the list if it exists*/
void *ll_get(List *list, int(*cmpr_func)(void *, void *), void *target);

/*Prints the contents of a list*/
int ll_print(List *list, void(*print_func)(void *));

#endif
