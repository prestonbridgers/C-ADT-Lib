Linked List
===========

The linked list implementation is completely abstract.
You can provide your own struct which it will store.
This means you will, in some cases, be required to write functions that operate on your specific struct.
For example, the ``ll_print`` method shown below requires a callback function to print your struct.

Headerfile
----------

The header file is called ``linked_list.h``.
The functions below are how you will interface with the code.

.. code-block:: c

	int ll_print(List *list, void(*print_func)(void *));
	int ll_add(List **list, void *filled_data);
	int ll_addEnd(List **list, void *filled_data);
	int ll_tail_get(List **tail, List *list);
	int ll_free(List *list);
	int ll_remove(List **list, int(*remove_func)(void *, void *), void *target);

Code Example
------------

The following example demonstrates a typical use case including the use of a callback function:

.. code-block:: c

	#include <stdio.h>
	#include <stdlib.h>

	#include "linked_list.h"

	/*
	 * In this example, we create a linked list of these
	 * PersonRecord structs.
	*/
	typedef struct{
		char *name;
		int age;
		int student_id;
	}PersonRecord;

	/*
	 * The pr_create function is a simple helper function.
	 *
	 * The pr_print_func function is meant to be used as a
	 * function pointer passed to the ll_print function.
	*/
	PersonRecord* 	pr_create(char *n, int a, int sid);
	void		pr_print_func(void *pr);
	int		pr_cmpr_func(void *a, void *b);

	int main(int argc, char **argv)
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

		// Freeing all memory associated with the list
		ll_free(pr_list);
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
 	* linked list how to print a PersonRecord.
	*/
	void pr_print_func(void *pr)
	{
		PersonRecord *pr_tmp = (PersonRecord *) pr;
		printf("%s:\n  student ID: %d\n  age: %d\n\n",
			pr_tmp->name, pr_tmp->student_id, pr_tmp->age);
	}

	/*
 	* Meant to be used as a function pointer to tell the
 	* linked list how to compare two PersonRecord structs.
	*/
	int pr_cmpr_func(void *a, void *b)
	{
		PersonRecord *prA = (PersonRecord*) a;
		PersonRecord *prB = (PersonRecord*) b;
	
		if (prA->student_id == prB->student_id)
			return 0;
	
		return 1;
	}
