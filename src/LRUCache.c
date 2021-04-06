#include <stdio.h>
#include <stdlib.h>
#include "LRUCache.h"
#define MAX_CAP 3000


struct ValueNode {
    int value;
    int key;
    ValueNode *next;
    ValueNode *prev;
};

struct LRUCache {
    ValueNode* head;
    ValueNode* tail;
    int len;
    int maxlen;
    ValueNode* keys[MAX_CAP];
};


void add_node(LRUCache* obj, ValueNode* new) {
    new->prev = NULL;
    new->next = obj->head;
    if (obj->head != NULL) obj->head->prev = new;
    else obj->tail = new;
    obj->head = new;
    return;
}

void seperate_node(LRUCache* obj, ValueNode* old){
    old->prev->next = old->next;
    if (old != obj->tail) old->next->prev = old->prev; //middle node case
    else obj->tail = old->prev;   //tail node case
    return;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* c = (LRUCache *) malloc(sizeof(LRUCache));
    c->len = 0; c->maxlen = capacity; c->head = c->tail = NULL;
    
    for (int i = 0; i < MAX_CAP; i++) {
        c->keys[i] = NULL;
    }
    return c;
}

int lRUCacheGet(LRUCache* obj, int key) {
    /*  prioritize element, return value*/
    if (obj->keys[key] == NULL) return -1;
    
    ValueNode* i = obj->keys[key];
    if (i != obj->head){    //move node to head, but not if node is already head
        seperate_node(obj, i);
        add_node(obj, i);
    }
    return obj->keys[key]->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->keys[key] != NULL) {
        obj->keys[key]->value = value; 
        return;
    }
    if (obj->len == obj->maxlen){   //seperate node from list, delete node, reset key in array
        int key = obj->tail->key;
        seperate_node(obj, obj->tail);
        free(obj->keys[key]);
        obj->keys[key] = NULL;
        obj->len -= 1;
    }
    ValueNode* new = (ValueNode *) malloc(sizeof(ValueNode));
    new->value = value; new->key = key; 
    add_node(obj, new);
    obj->keys[key] = new;   //put pointer in array
    obj->len += 1;
    return;
}

void lRUCacheFree(LRUCache* obj) {
    for (int i=0; i < MAX_CAP; i++){
        ValueNode* x = obj->keys[i];
        if (x != NULL) free(x);
    }
    return;
}