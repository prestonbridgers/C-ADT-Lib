#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct{
	char *name;
	int age;
	int student_id;
}PersonRecord;

PersonRecord* 	pr_create(char *n, int a, int sid);
void 			pr_print_func(void *pr);
int				pr_cmpr_func(void *a, void *b);

/*
 * main function
*/
int main(int argc, char **argv)
{
	List *pr_list = NULL;

	PersonRecord *pr1 = pr_create("John", 36, 0);
	PersonRecord *pr2 = pr_create("Curt", 20, 1);
	PersonRecord *pr3 = pr_create("Kassy", 23, 2);
	PersonRecord *pr4 = pr_create("Sean", 22, 3);

	ll_add(&pr_list, pr1);
	ll_addEnd(&pr_list, pr2);
	ll_add(&pr_list, pr3);
	ll_addEnd(&pr_list, pr4);

	ll_print(pr_list, &pr_print_func);

	ll_remove(&pr_list, &pr_cmpr_func, pr4);

	ll_print(pr_list, &pr_print_func);

	ll_free(pr_list);
	return 0;
}


/*
 * Fills a PersonRecord struct and returns it.
*/
PersonRecord *pr_create(char *n, int a, int sid)
{
	PersonRecord *pr_tmp = calloc(1, sizeof(PersonRecord));
	pr_tmp->name = n;
	pr_tmp->age = a;
	pr_tmp->student_id = sid;
	return pr_tmp;
}

/*
 * Meant to be used as a function pointer to tell the
 * linked list how to print a PersonRecord.
*/
void pr_print_func(void *pr)
{
	printf("In print func\n");
	PersonRecord *pr_tmp = (PersonRecord *) pr;
	printf("%s:\n  student ID: %d\n  age: %d\n\n",
		pr_tmp->name, pr_tmp->student_id, pr_tmp->age);
}

int	pr_cmpr_func(void *a, void *b)
{
	PersonRecord *prA = (PersonRecord*) a;
	PersonRecord *prB = (PersonRecord*) b;

	if (prA->student_id == prB->student_id)
		return 0;

	return 1;
}
