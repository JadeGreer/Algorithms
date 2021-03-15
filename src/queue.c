// Queue implementation based on a max sized array

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define max 100

struct Queue {
    int queue[max + 1];  // circular array
    int head, tail; // start and end of queue
};

void put(Queue * q, int v) {
    // add an element to the end of array
    q->queue[q->tail++] = v;
    if (q->tail > max) 
        q->tail = 0;
}

int get(Queue * q) {
    // get element at head of queue
    int t = q->queue[q->head++];
    if (q->head > max) q->head = 0;
    return t;
} 

Queue * queue_init() {
    Queue * q = (Queue *) malloc(sizeof(Queue));
    q->head = 0;
    q->tail = 0;
    q->queue[q->head];
    return q;
}

int is_empty(Queue * q) {
    return q->head == q->tail;
}

void queue_free(Queue * q) {
    free(q);
}

void print_queue(Queue * q) {
    for (int i = 0; i <= (q->tail); i++)
        printf("%c", q->queue[i]);
}