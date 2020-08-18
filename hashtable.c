#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

HashTable *ht_create(uint32_t n)
{
	HashTable *tmp = calloc(1, sizeof(*tmp));
	tmp->num_buckets = n;
	tmp->buckets = calloc(tmp->num_buckets, sizeof(*tmp->buckets));
}

uint32_t ht_hash(HashTable *ht, char *key)
{
	uint32_t sum = 0;
	for (uint32_t i = 0; i < strlen(key); i++)
		sum += key[i];
	return sum % ht->num_buckets;
}

uint32_t ht_retrieve(HashTable *ht, char *key)
{
	uint32_t index = ht_hash(ht, key);
	return ht->buckets[index];
}

int ht_insert(HashTable **ht, char *key, uint32_t value)
{
	if (key == NULL)
		return 1;

	uint32_t hash_value = ht_hash(*ht, key);

	(*ht)->buckets[hash_value] = value;

	return 0;
}

int ht_print(HashTable *ht)
{
	if(ht == NULL)
		return 1;

	printf("Printing HashTable:\n");
	for (uint8_t i = 0; i < ht->num_buckets; i++)
		printf("Bucket %d: %d\n", i, ht->buckets[i]);
	putc('\n', stdout);

	return 0;
}
