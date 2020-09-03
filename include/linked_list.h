#ifndef H_INCLUDED_LINKEDLIST
#define H_INCLUDED_LINKEDLIST

/*List Node Struct*/
typedef struct ListNode{
	void *data;				// The data being stored in the node.
	struct ListNode *next;	// The pointer to the next node.
}ListNode;

/*List Struct*/
typedef struct List{
	struct ListNode *head;	// Dummy node book-ending the beginning.
	struct ListNode *tail;	// Dummy node book-ending the end.
}List;


List* ll_create();
int   ll_destroy(List *list); 
int   ll_add(List *list, void *filled_data);
int   ll_remove(List *list, int(*cmpr_func)(void *, void *), void *target); 
void* ll_get(List *list, int(*cmpr_func)(void *, void *), void *target);
int   ll_print(List *list, void(*print_func)(void *));

#endif
