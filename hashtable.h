#ifndef H_INCLUDED_HASHTABLE
#define H_INCLUDED_HASHTABLE

typedef struct HashTable{
	uint32_t num_buckets;
	uint32_t *buckets;
}HashTable;

HashTable *ht_create(uint32_t n);
int ht_insert(HashTable **ht, char *key, uint32_t value);
int ht_print(HashTable *ht);
uint32_t ht_retrieve(HashTable *ht, char *key);

#endif
