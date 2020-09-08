Queue
=====

The queue implementation is represented via circular array.

Headerfile
----------

The header file is called ``queue.h``.
The functions below are how you will interface with the code.

.. code-block:: c

	Queue*	queue_create();
	void	queue_destroy(Queue *q);
	void 	queue_en(Queue *q, void *data);
	void* 	queue_de(Queue *q, void *data);

Code Example
------------

The following example demonstrates a typical use case including the use of a callback function:

.. code-block:: c

	int main(void)
	{
		typedef struct
		{
			char *name;
			int age;
		}Person;

		Person *g;
		Queue *que = queue_create();

		Person p1 = (Person) {"Curt", 18};
		Person p2 = (Person) {"James", 20};
		Person p3 = (Person) {"Kassy", 25};
	
		queue_en(que, &p1);
	
		g = (Person*) queue_de(que);
		if (g != NULL)
			printf("g: %s is %d years old\n", g->name, g->age);

		queue_destroy(que);
		return 0;
	}
