#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "hashtable.h"
#include "linked_list.h"

void print_func(void *v)
{
	MyData *tmp = (MyData*) v;
	printf("Data Entry: %d\n", tmp->data);
}

int main(void)
{
	HashTable *ht = ht_create(10);

	ht_insert(&ht, "Curt", 20);
	ht_insert(&ht, "Michael", 18);
	ht_insert(&ht, "James", 10);
	ht_insert(&ht, "Karl", 38);
	ht_insert(&ht, "Piper", 48);
	ht_insert(&ht, "Jimmy", 39);
	ht_insert(&ht, "Jake", 27);
	ht_insert(&ht, "Brandon", 26);
	ht_insert(&ht, "Bryan", 59);
	ht_insert(&ht, "Blake", 50);
	ht_insert(&ht, "Preston", 20);
	ht_insert(&ht, "Linden", 38);
	ht_insert(&ht, "Lynn", 33);
	ht_insert(&ht, "Charles", 44);
	ht_insert(&ht, "Brendan", 55);
	ht_insert(&ht, "Jacob", 64);
	ht_insert(&ht, "Christian", 21);
	ht_insert(&ht, "Jennifer", 8);
	ht_insert(&ht, "Kassy", 73);
	ht_insert(&ht, "Josh", 74);
	ht_insert(&ht, "Terry", 6);
	ht_insert(&ht, "Jody", 12);
	ht_insert(&ht, "Christopher", 90);
	ht_insert(&ht, "Topher", 23);
	ht_insert(&ht, "Jordan", 56);
	ht_insert(&ht, "Ezekiel", 35);

	ht_print(ht, &print_func);

	MyData *ret = (MyData *) ht_retrieve(ht, "Curt");
	printf("\nht_retrieve(\"Curt\") = %d\n", ret->data);

	ret = (MyData *) ht_retrieve(ht, "Michael");
	printf("ht_retrieve(\"Michael\") = %d\n", ret->data);

	ret = (MyData *) ht_retrieve(ht, "James");
	printf("ht_retrieve(\"James\") = %d\n", ret->data);

	ht_free(ht);
	return 0;
}
