Hash Tables
===========

The hash table implementation is a very simple one.
It does collision resolution via seperate chaining with linked lists; it uses the same linked list implementation provided with this library.
I have only implemented one, very simple character folding hash function.
I plan on implementing more hash functions and making small interface changes in the future.

Header File
-----------

.. code-block:: c

	typedef struct
	{
		char *key;
		uint32_t data;
	}MyData;

	typedef struct HashTable{
		uint32_t num_buckets;
		List **buckets;
	}HashTable;

	HashTable *ht_create(uint32_t n);
	uint32_t ht_free(HashTable *ht);
	uint32_t ht_insert(HashTable **ht, char *key, uint32_t value);
	uint32_t ht_print(HashTable *ht, void(*print_func)(void *));
	void *ht_retrieve(HashTable *ht, char *key);

Code Example
------------

.. code-block:: c

	#include <stdio.h>
	#include <stdint.h>
	#include <string.h>

	#include "hashtable.h"
	#include "linked_list.h"

	/*
	 * This function is mean to be used as a function pointer
	 *   to the ht_print() function call below. This tells the
	 *   HashTable how to print the data it is storing.
	*/
	void print_func(void *v)
	{
		MyData *tmp = (MyData*) v;
		printf("Data Entry: %d\n", tmp->data);
	}

	int main(void)
	{
		// Creating a HashTable with 10 buckets
		HashTable *ht = ht_create(10);

		// Inserting (key, value) pairs into the HashTable
		ht_insert(&ht, "Curt", 20);
		ht_insert(&ht, "Michael", 18);
		ht_insert(&ht, "James", 10);
		ht_insert(&ht, "Karl", 38);
		ht_insert(&ht, "Piper", 48);
		ht_insert(&ht, "Jimmy", 39);
		ht_insert(&ht, "Jake", 27);

		// Printing the HashTable with the print_func defined above
		// This is similar to the Linked List implementation of ll_print()
		ht_print(ht, &print_func);

		/*
		 * Retrieving data is done by casting the return value of
		 *   ht_retrieve() to the datatype you are storing.
		*/
		MyData *ret = (MyData *) ht_retrieve(ht, "Curt");
		printf("\nht_retrieve(\"Curt\") = %d\n", ret->data);
	
		ret = (MyData *) ht_retrieve(ht, "Michael");
		printf("ht_retrieve(\"Michael\") = %d\n", ret->data);

		ret = (MyData *) ht_retrieve(ht, "James");
		printf("ht_retrieve(\"James\") = %d\n", ret->data);

		// Freeing all memory associated with the HashTable
		ht_free(ht);
		return 0;
	}
