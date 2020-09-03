#ifndef H_INCLUDED_HASHTABLE
#define H_INCLUDED_HASHTABLE

#include "linked_list.h"

/*
 * The only data that is associated with the
 *   hashtable is the number of buckets in it
 *   and an array of linked lists to store its
 *   entries.
*/
typedef struct{
	uint32_t num_buckets;
	List **buckets;
}HashTable;

HashTable* ht_create(uint32_t n);
uint32_t   ht_free(HashTable *ht);
uint32_t   ht_insert(HashTable **ht, void *data);
uint32_t   ht_print(HashTable *ht, void(*print_func)(void *));
void*      ht_retrieve(HashTable *ht, char *key);

#endif
