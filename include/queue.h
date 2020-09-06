#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define STACK_INIT_CAP 3

typedef struct
{
	int capacity;
	int num_elements;
	int start;
	int end;
	void *data[STACK_INIT_CAP];
}Queue;

Queue* queue_create();
void   queue_destroy(Queue *q);
void   queue_en(Queue *q, void *data);
void   *queue_de(Queue *q);

#endif
