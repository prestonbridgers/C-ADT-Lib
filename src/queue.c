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
	// TODO: Make this do something
	free(q);
}

void queue_en(Queue *q, void *data)
{
	// IF: the queue is full
	if (q->num_elements == q->capacity)
	{
		fprintf(stderr, "Attempted to enqueue on a full array!\n");
		return;
	}

	q->data[q->end] = data;
	q->end++;
	q->num_elements++;

	if (q->end == q->capacity)
		q->end = 0;
}

void *queue_de(Queue *q)
{
	// IF: Queue is empty
	if (q->num_elements == 0)
	{
		fprintf(stderr, "Attempted to dequeue from an empty array!\n");
		return NULL;
	}

	void *data = q->data[q->start];
	q->start++;
	q->num_elements--;

	if (q->start == q->capacity)
		q->start = 0;
	
	return data;
}

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
