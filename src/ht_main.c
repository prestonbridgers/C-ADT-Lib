#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "linked_list.h"

/*
 * Defining the data to store into the hashtable
 *  the first field is assumed to be a char array
 *  as it will be used as the key for the hashtable.
*/
typedef struct
{
	char *name;
	uint8_t age;
}PersonRecord;

/*
 * This function is meant to be used as a function
 *   pointer to tell the hashtable how to print the
 *   data that is stored within it.
*/
void pr_print_func(void *v)
{
	PersonRecord *tmp = (PersonRecord*) v;
	printf("Data Entry: %s is %d years old\n", tmp->name, tmp->age);
}

// Helper function for creating PersonRecords.
PersonRecord *pr_create(char *name, uint8_t age)
{
	PersonRecord *pr = calloc(1, sizeof(*pr));
	pr->name = name;
	pr->age = age;

	return pr;
}

int main(void)
{
	// Creating the hashtable with 10 buckets
	HashTable *ht = ht_create(10);

	// Creating my data
	PersonRecord *pr1 = pr_create("Curt", 20);
	PersonRecord *pr2 = pr_create("Michael", 34);
	PersonRecord *pr3 = pr_create("John", 15);

	// Inserting data into the hashtable
	ht_insert(&ht, pr1);
	ht_insert(&ht, pr2);
	ht_insert(&ht, pr3);

	// Printing the hashtable
	ht_print(ht, &pr_print_func);

	// Retrieving the data
	PersonRecord *ret = (PersonRecord *) ht_retrieve(ht, "Curt");
	printf("\nht_retrieve(\"Curt\") = %s is %d\n", ret->name, ret->age);

	ret = (PersonRecord *) ht_retrieve(ht, "Michael");
	printf("ht_retrieve(\"Michael\") = %s is %d\n", ret->name, ret->age);

	ret = (PersonRecord *) ht_retrieve(ht, "John");
	printf("ht_retrieve(\"James\") = %s is %d\n", ret->name, ret->age);

	// Freeing memory 
	ht_free(ht);
	return 0;
}
