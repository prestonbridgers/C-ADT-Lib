#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue *queue_create()
{
	Queue *new_queue = calloc(1, sizeof *new_queue);
	
	new_queue->capacity = STACK_INIT_CAP;
	new_queue->num_elements = 0;
	new_queue->start = 0;
	new_queue->end = 0;

	for (size_t i = 0; i < new_queue->capacity; i++)
		new_queue->data[i] = NULL;
	
	return new_queue;
}

void queue_destroy(Queue *q)
{
	
}

void queue_en(Queue *q, void *data)
{
	if (q->data[q->end] == NULL)
	{
		q->data[q->end] = data;
		q->end++;
	}
}

void *queue_de(Queue *q)
{
	void *data = q->data[q->start];
	q->start++;
	return data;
}

int main(void)
{
	typedef struct
	{
		char *name;
		int age;
	}Person;

	Queue *que = queue_create();

	for (int i = 0; i < que->capacity; i++)
		if (que->data[i] == NULL)
			printf("Queue #%d: NULL\n", i);

	Person p1 = (Person) {"Curt", 18};
	Person p2 = (Person) {"James", 20};
	Person p3 = (Person) {"Kassy", 25};
	
	queue_en(que, &p1);
	queue_en(que, &p2);
	queue_en(que, &p3);

	Person *g = (Person*) queue_de(que);
	printf("g: %s is %d years old\n", g->name, g->age);

	g = (Person*) queue_de(que);
	printf("g: %s is %d years old\n", g->name, g->age);

	g = (Person*) queue_de(que);
	printf("g: %s is %d years old\n", g->name, g->age);
	
	queue_destroy(que);
	return 0;
}
