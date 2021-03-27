#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

int test1(){
    Stack * s = stackinit();
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4;
    push(s, &x1);
    push(s, &x2);
    push(s, &x3);
    push(s, &x4);
    int * x = ((int *) pop(s));
    assert(*x == 4);
    return 1;
}

int test2(){
    Stack * s = stackinit();
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4;
    push(s, &x1);
    push(s, &x2);
    push(s, &x3);
    push(s, &x4);
    int * a = ((int *) pop(s));
    int * b = ((int *) pop(s));
    int * c = ((int *) pop(s));
    assert( (*a) * (*b) + (*c) == 14 && (*a) * (*c) + (*b) == 11);
    return 1;
}
int test3(){
    Stack * s = stackinit();
    int x2 = 2, x25 = 25, x1 = 1;
    push(s,&x2);
    push(s,&x25);
    push(s,&x1);
    pop(s);
    pop(s);
    assert(!stackempty(s));
    pop(s);
    assert(stackempty(s));
    return 1;
}
int test4(){
    Stack * s = stackinit();
    assert(stackempty(s));
    return 1;
}

int main(){ 
    assert(test1() && test2() && test3() && test4());
    printf("Your stacks are all good! \n");
    return 0;
}
