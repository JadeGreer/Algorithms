typedef struct Stack Stack;

Stack * stackinit();
void push(Stack *, int);
int pop(Stack *);
int stackempty(Stack *);