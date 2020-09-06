Stack
=====

The stack implementation is represented via a linked list.

Headerfile
----------

The header file is called ``stack.h``.
The functions below are how you will interface with the code.

.. code-block:: c

	Stack* 	stack_create();
	void	stack_destroy();
	int	stack_push(Stack *st, void *data);
	void*	stack_pop(Stack st);

Code Example
------------

The following example demonstrates a typical use case including the use of a callback function:

.. code-block:: c

	int main(void)
	{
		Stack *st = stack_create();

		typedef struct
		{
			char *name;
			int age;
		} Person;

		Person a = (Person) {"Curt", 18};
		Person b = (Person) {"James", 20};
		Person c = (Person) {"John", 25};

		stack_push(st, &a);

		Person *get_a = (Person *) stack_pop(st);
		printf("Popped: %s is %d years old.\n", get_a->name, get_a->age);

		get_a = (Person *) stack_pop(st);
		if (get_a == NULL)
			printf("Popped: End of stack reached\n\n");
	
		stack_push(st, &b);
		stack_push(st, &c);

		get_a = (Person *) stack_pop(st);
		printf("Popped: %s is %d years old.\n", get_a->name, get_a->age);

		get_a = (Person *) stack_pop(st);
		printf("Popped: %s is %d years old.\n", get_a->name, get_a->age);

		get_a = (Person *) stack_pop(st);
		if (get_a == NULL)
			printf("Popped: End of stack reached\n");

		stack_destroy(st);
		return 0;
	}


