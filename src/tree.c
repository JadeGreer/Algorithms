#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "stack.h"

typedef struct Tree_Node Tree_Node;

struct Tree_Node{
    char info;
    Tree_Node *l, *r;
};

struct Tree{
    Tree_Node *z, *root;
};

Tree* tree_init(char* c) {
    Tree* T = (Tree*) malloc (sizeof(Tree));
    Stack* stack = stackinit();
    T->z = (Tree_Node*) malloc (sizeof(Tree_Node)); 
    T->z->l = T->z; T->z->r = T->z;
    T->root = T->z;

    int len = strlen(c);
    for (int i = 0; i < len; i++) {
        Tree_Node* x = (Tree_Node*) malloc (sizeof(Tree_Node));
        x->info = c[i]; x->l = T->z; x->r = T->z;
        if(c[i] == '+' || c[i] == '*') {
            x->r = pop(stack); x->l = pop(stack);
            T->root = x;
        }
        push(stack, x);
    }
    return T;
}

void visit(Tree_Node * n){
    printf("%c \n", n->info);
};

void preorder_traverse(Tree* t){
    Stack* s = stackinit();
    push(s, t->root);

    while(!stackempty(s)) {
        Tree_Node* x = pop(s);
        visit(x);
        if (x->r != t->z) push(s, x->r);
        if (x->l != t->z) push(s, x->l);
    }
}

int max(int a, int b) {return a > b ? a : b;}

int tree_length_recursive(Tree_Node* t, Tree_Node* z) {
    if (t == z) 
        return 0;
    else
        return max(tree_length_recursive(t->l, z), tree_length_recursive(t->r, z)) + 1;
}

int tree_length(Tree* t){
    return tree_length_recursive(t->root, t->z);
}