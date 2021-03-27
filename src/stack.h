typedef struct Stack Stack;

Stack * stackinit();
void push(Stack *, void *);
void * pop(Stack *);
int stackempty(Stack *);