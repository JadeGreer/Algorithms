#include "stack.h"

typedef struct Tree Tree;

Tree* tree_init(char*);
void preorder_traverse(Tree*);
int tree_len(Tree* t);
int tree_length(Tree* t);