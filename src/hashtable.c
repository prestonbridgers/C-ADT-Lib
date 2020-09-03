#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "hashtable.h"

/*
 * Allocates memory for and returns a pointer to a hashtable
 *   with n buckets.
*/
HashTable *ht_create(uint32_t n)
{
	HashTable *tmp = calloc(1, sizeof(*tmp));
	tmp->num_buckets = n;
	tmp->buckets = calloc(tmp->num_buckets, sizeof(*tmp->buckets));

	for(uint32_t i = 0; i < tmp->num_buckets; i++)
		tmp->buckets[i] = ll_create();

	return tmp;
}

/*
 * Frees all memory associated with hashtable, ht.
*/
uint32_t ht_free(HashTable *ht)
{
	for (uint32_t i = 0; i < ht->num_buckets; i++)
		ll_destroy(ht->buckets[i]);
	free(ht->buckets);
	free(ht);

	return 0;
}

/*
 * Private hash function that folds the ASCII
 *   codes of a key and returns it mod the number
 *   of buckets in hashtable, ht.
*/
uint32_t ht_hash_ascii(HashTable *ht, char *key)
{
	uint32_t hash = 0;
	for (uint32_t i = 0; i < strlen(key); i++)
		hash += key[i];
	uint32_t index = hash % ht->num_buckets;
	return index;
}

/*
 * Private compare functions that compares keys of
 *   two void pointers.
 *
 * Pre-conditions:
 *   The first piece of data stored at a and b must
 *     be character strings.
*/
int ht_cmpr_private(void *a, void *b)
{
	struct tmp_struct
	{
		char *key;
	};

	struct tmp_struct *tmpA = (struct tmp_struct *) a;
	struct tmp_struct *tmpB = (struct tmp_struct *) b;
	
	if (strcmp(tmpA->key, tmpB->key) == 0)
		return 0;

	return 1;
}

/*
 * Searches hashtable for and returns data from
 *   (key, data) pair.
*/
void *ht_retrieve(HashTable *ht, char *key)
{
	uint32_t index = ht_hash_ascii(ht, key);

	struct
	{
		char *key;
	} search_target;
	search_target.key = key;

	void *item = ll_get(ht->buckets[index], ht_cmpr_private, &search_target);

	return item;
}

/*
 * Inserts data into hashtable, ht.
*/
uint32_t ht_insert(HashTable **ht, void *data)
{
	uint32_t hash_value;

	struct KeyStruct
	{
		char *key;
	};
	struct KeyStruct *key_data = (struct KeyStruct *) data;
	
	hash_value = ht_hash_ascii(*ht, key_data->key);
	ll_add((*ht)->buckets[hash_value], data);

	return 0;
}

/*
 * Prints the hashtable using print_func
*/
uint32_t ht_print(HashTable *ht, void(*print_func)(void *))
{
	if(ht == NULL)
		return 1;

	printf("Printing HashTable:\n");
	for(uint8_t i = 0; i < ht->num_buckets; i++)
	{
		printf("Bucket #%d:\n", i);
		ll_print(ht->buckets[i], print_func);
	}

	return 0;
}
