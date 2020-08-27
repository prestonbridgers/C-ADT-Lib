#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "linked_list.h"

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

	return 0;
}
// ~~~~~~~~~~~~~~~~~~~End Main Function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
 * This function demonstrates the linked list interface.
*/
int linkedlist_demo(void)
{
	// The list MUST be initialized to NULL
	List *pr_list = NULL;

	// Creating our data
	PersonRecord *pr1 = pr_create("John", 36, 0);
	PersonRecord *pr2 = pr_create("Curt", 20, 1);
	PersonRecord *pr3 = pr_create("Kassy", 23, 2);
	PersonRecord *pr4 = pr_create("Sean", 22, 3);

	// Adding our data to the list
	ll_add(&pr_list, pr1);
	ll_addEnd(&pr_list, pr2);
	ll_add(&pr_list, pr3);
	ll_addEnd(&pr_list, pr4);

	/*
	 * Removing pr1 from the list using the
	 * PersonRecord comparison function we
	 * created.
	*/
	ll_remove(&pr_list, &pr_cmpr_func, pr1);

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
	printf("Getting pr2 from the list:\n");
	pr_print_func(pr);

	// Freeing all memory associated with the list
	ll_free(pr_list);
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
	void *ret = ht_retrieve(ht, "Curt");
	pr_print_func(ret);

	ret = (PersonRecord *) ht_retrieve(ht, "Michael");
	pr_print_func(ret);

	ret = (PersonRecord *) ht_retrieve(ht, "John");
	pr_print_func(ret);

	// Freeing memory 
	ht_free(ht);
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
	printf("%s:\n  student ID: %d\n  age: %d\n\n",
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
