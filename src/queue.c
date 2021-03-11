#include <stdio.h>
#include "queue.h"

#include <stdio.h>

#define max 100

static int queue[max+1], head, tail;


void put(int v) {
    queue[tail++] = v;
    if (tail > max) tail = 0;
}

int get() {
    int t = queue[head++];
    if (head > max) head = 0;
    printf("%d \n", t);
} 

void queue_init() {
    head = 0; tail = 0;
}

int queue_empty() {
    return head == tail;
}

int main() {
    queue_init();
    put(1);
    put(2);
    put(3);
    get();
    return 0;
}