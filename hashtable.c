#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "hashtable.h"

HashTable *ht_create(uint32_t n)
{
	HashTable *tmp = calloc(1, sizeof(*tmp));
	tmp->num_buckets = n;
	tmp->buckets = calloc(tmp->num_buckets, sizeof(*tmp->buckets));

	for(uint32_t i = 0; i < tmp->num_buckets; i++)
		tmp->buckets[i] = NULL;

	return tmp;
}

uint32_t ht_hash_ascii(HashTable *ht, char *key)
{
	uint32_t hash = 0;
	for (uint32_t i = 0; i < strlen(key); i++)
		hash += key[i];
	uint32_t index = hash % ht->num_buckets;
	return index;
}

uint32_t ht_retrieve(HashTable *ht, char *key)
{
	uint32_t index = ht_hash_ascii(ht, key);
	//return ht->buckets[index];
	//TODO
	return 0;
}

uint32_t ht_insert(HashTable **ht, char *key, uint32_t value)
{
	if (key == NULL)
		return 1;

	MyData *tmp = calloc(1, sizeof(*tmp));
	tmp->key = key;
	tmp->data = value;
	
	uint32_t hash_value = ht_hash_ascii(*ht, key);
	ll_add(&((*ht)->buckets[hash_value]), tmp);

	return 0;
}

uint32_t ht_print(HashTable *ht)
{
	if(ht == NULL)
		return 1;

	printf("Printing HashTable:\n");
	for (uint8_t i = 0; i < ht->num_buckets; i++)
		printf("Bucket %d: %d\n", i, ht->buckets[i]);
	putc('\n', stdout);

	return 0;
}
