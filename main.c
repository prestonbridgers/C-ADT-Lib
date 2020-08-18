#include <stdio.h>
#include <stdint.h>

#include "hashtable.h"

int main(void)
{
	HashTable *ht = ht_create(10);

	ht_insert(&ht, "Curt", 20);
	ht_insert(&ht, "Michael", 18);
	ht_insert(&ht, "James", 10);

	ht_print(ht);

	printf("ht_retrieve(\"Curt\") = %d\n", ht_retrieve(ht, "Curt"));
	printf("ht_retrieve(\"Michael\") = %d\n", ht_retrieve(ht, "Michael"));
	printf("ht_retrieve(\"James\") = %d\n", ht_retrieve(ht, "James"));

	return 0;
}
