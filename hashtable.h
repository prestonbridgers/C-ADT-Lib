#ifndef H_INCLUDED_HASHTABLE
#define H_INCLUDED_HASHTABLE

#include "linked_list.h"

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
uint32_t ht_insert(HashTable **ht, char *key, uint32_t value);
uint32_t ht_print(HashTable *ht);
uint32_t ht_retrieve(HashTable *ht, char *key);

#endif
