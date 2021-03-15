#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


typedef struct Node Node;

struct Node {
    int key; 
    Node *next;
};

struct Stack {
    Node *head, *z, *t;
};


Stack * stackinit() {
    Stack * s = (Stack *) malloc(sizeof(Stack));
    s->head = (Node *) malloc(sizeof (Node));
    s->z = (Node *) malloc(sizeof (Node));
    s->head->next = s->z; 
    s->head->key = 0;
    s->z->next = s->z;
    return s;
}

void push(Stack * s, int v){
    s->t = (Node *) malloc(sizeof (Node));
    s->t->key = v; s->t->next = s->head->next;
    s->head->next = s->t;
}
int pop(Stack * s){
    int x;
    s->t = s->head->next;
    s->head->next = s->t->next;
    x = s->t->key;
    free(s->t);
    return x;
}
int stackempty(Stack * s){
    return s->head->next == s->z;
}
