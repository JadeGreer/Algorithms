// queue header file
#ifndef _Queue
#define _Queue

typedef struct Queue Queue;

void put(Queue * q, int v);
int get(Queue * q);
Queue * queue_init();
int is_empty(Queue * q);
void queue_free(Queue * q);
void print_queue(Queue * q);

#endif


