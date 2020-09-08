#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "linked_list.h"
#include "stack.h"
#include "queue.h"

/*
 * The data structure that will be used for both
 *   the hashtable and linked list demos.
*/
typedef struct{
	char *name;
	int age;
	int student_id;
}PersonRecord;

// Function prototypes
int 			linkedlist_demo(void);
int 			hashtable_demo(void);
int             stack_demo(void);
int				queue_demo(void);
PersonRecord* 	pr_create(char *n, int a, int sid);
void			pr_print_func(void *pr);
int				pr_cmpr_func(void *a, void *b);

// ~~~~~~~~~~~~~~~~~~~~~~Main Function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(void)
{
	printf("~~~~~~~~~~~~~~~~Hashtable Demo~~~~~~~~~~~~~~~~\n");
	hashtable_demo();
	printf("~~~~~~~~~~~~~~~Linked List Demo~~~~~~~~~~~~~~~\n");
	linkedlist_demo();
	printf("~~~~~~~~~~~~~~~Stack Demo~~~~~~~~~~~~~~~\n");
	stack_demo();
	printf("~~~~~~~~~~~~~~~Queue Demo~~~~~~~~~~~~~~~\n");
	queue_demo();

	return 0;
}
// ~~~~~~~~~~~~~~~~~~~End Main Function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
 * This function demonstrates the linked list interface.
*/
int linkedlist_demo(void)
{
	// The list MUST be initialized to NULL
	List *pr_list = ll_create();

	// Creating our data
	PersonRecord *pr1 = pr_create("John", 36, 0);
	PersonRecord *pr2 = pr_create("Curt", 20, 1);
	PersonRecord *pr3 = pr_create("Kassy", 23, 2);
	PersonRecord *pr4 = pr_create("Sean", 22, 3);

	// Adding our data to the list
	ll_add(pr_list, pr1);
	ll_add(pr_list, pr2);
	ll_add(pr_list, pr3);
	ll_add(pr_list, pr4);

	/*
	 * Removing pr1 from the list using the
	 * PersonRecord comparison function we
	 * created.
	*/
	ll_remove(pr_list, &pr_cmpr_func, pr1);

	/*
	 * Printing the contents of the list as defined
	 * by our pr_print_func
	*/
	ll_print(pr_list, &pr_print_func);

	// Creating a target to search for and get from the list.
	PersonRecord target = (PersonRecord) {NULL, 0, 0};
	target.student_id = 1;

	// Searching/getting the target created above from the list.
	void *pr = ll_get(pr_list, &pr_cmpr_func, &target);
	printf("\nGetting pr2 from the list:\n");
	pr_print_func(pr);

	// Freeing all memory associated with the list
	ll_destroy(pr_list);
	free(pr1);
	free(pr2);
	free(pr3);
	free(pr4);
	return 0;
}

/*
 * This function demonstrates the hashtable interface.
*/
int hashtable_demo(void)
{
	// Creating the hashtable with 10 buckets
	HashTable *ht = ht_create(10);

	// Creating my data
	PersonRecord *pr1 = pr_create("Curt", 20, 0);
	PersonRecord *pr2 = pr_create("Michael", 34, 1);
	PersonRecord *pr3 = pr_create("John", 15, 2);

	// Inserting data into the hashtable
	ht_insert(&ht, pr1);
	ht_insert(&ht, pr2);
	ht_insert(&ht, pr3);

	// Printing the hashtable
	ht_print(ht, &pr_print_func);

	// Retrieving the data
	printf("\nRetrieving all data from the hashmap:\n");
	PersonRecord *ret = (PersonRecord*) ht_retrieve(ht, "Curt");
	pr_print_func(ret);

	ret = (PersonRecord *) ht_retrieve(ht, "Michael");
	pr_print_func(ret);

	ret = (PersonRecord *) ht_retrieve(ht, "John");
	pr_print_func(ret);

	// Freeing memory 
	ht_free(ht);
	free(pr1);
	free(pr2);
	free(pr3);
	return 0;
}

int stack_demo()
{
	Stack *st = stack_create();

	typedef struct
	{
		char *name;
		int age;
	} Person;

	Person a = (Person) {"Curt", 18};
	Person b = (Person) {"James", 20};
	Person c = (Person) {"John", 25};

	stack_push(st, &a);

	Person *get_a = (Person *) stack_pop(st);
	printf("Popped: %s is %d years old.\n", get_a->name, get_a->age);

	get_a = (Person *) stack_pop(st);
	if (get_a == NULL)
		printf("Popped: End of stack reached\n\n");
	
	stack_push(st, &b);
	stack_push(st, &c);

	get_a = (Person *) stack_pop(st);
	printf("Popped: %s is %d years old.\n", get_a->name, get_a->age);

	get_a = (Person *) stack_pop(st);
	printf("Popped: %s is %d years old.\n", get_a->name, get_a->age);

	get_a = (Person *) stack_pop(st);
	if (get_a == NULL)
		printf("Popped: End of stack reached\n");

	stack_destroy(st);
	return 0;
}

int queue_demo()
{
	typedef struct
	{
		char *name;
		int age;
	}Person;

	Person *g;
	Queue *que = queue_create();

	Person p1 = (Person) {"Curt", 18};
	Person p2 = (Person) {"James", 20};
	Person p3 = (Person) {"Kassy", 25};
	
	queue_en(que, &p1);

	g = (Person*) queue_de(que);
	if (g != NULL)
		printf("g: %s is %d years old\n", g->name, g->age);

	queue_destroy(que);
	return 0;
}

/*
 * Fills a PersonRecord struct and returns it.
*/
PersonRecord *pr_create(char *n, int a, int sid)
{
	PersonRecord *pr_tmp = calloc(1, sizeof(PersonRecord));
	pr_tmp->name = n;
	pr_tmp->age = a;
	pr_tmp->student_id = sid;
	return pr_tmp;
}

/*
 * Meant to be used as a function pointer to tell the
 *   datastructures how to print a PersonRecord struct.
*/
void pr_print_func(void *pr)
{
	PersonRecord *pr_tmp = (PersonRecord *) pr;
	printf("%s:\n  student ID: %d\n  age: %d\n",
		pr_tmp->name, pr_tmp->student_id, pr_tmp->age);
}

/*
 * Meant to be used as a function pointer to tell the
 *   datastructures how to compare two PersonRecord structs.
*/
int pr_cmpr_func(void *a, void *b)
{
	PersonRecord *prA = (PersonRecord*) a;
	PersonRecord *prB = (PersonRecord*) b;

	if (prA->student_id == prB->student_id)
		return 0;
	
	return 1;
}
