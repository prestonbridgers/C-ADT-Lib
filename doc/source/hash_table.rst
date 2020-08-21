Hash Tables
===========

Hash tables are currently partially implemented and is still very much a work in progress.

Header File
-----------

.. code-block:: c

	HashTable *ht_create(uint32_t n);
	int ht_insert(HashTable **ht, char *key, uint32_t value);
	int ht_print(HashTable *ht);
	uint32_t ht_retrieve(HashTable *ht, char *key);

Code Example
------------

.. code-block:: c
	
	#include <stdio.h>
	#include <stdint.h>

	#include "hashtable.h"

	int main(void)
	{
		// Creating the hash table with ht_create
		HashTable *ht = ht_create(10);

		// Inserting (key, value) pairs into the hash table
		ht_insert(&ht, "Curt", 20);
		ht_insert(&ht, "Michael", 18);
		ht_insert(&ht, "James", 10);

		// Printing the contents of the has table
		ht_print(ht);

		/*
		 * Retrieving values from the hash table with ht_retrieve
		 * and printing them
		*/
		printf("ht_retrieve(\"Curt\") = %d\n", ht_retrieve(ht, "Curt"));
		printf("ht_retrieve(\"Michael\") = %d\n", ht_retrieve(ht, "Michael"));
		printf("ht_retrieve(\"James\") = %d\n", ht_retrieve(ht, "James"));

		return 0;
	}
