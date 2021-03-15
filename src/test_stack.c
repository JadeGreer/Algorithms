#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

int test1(){
    Stack * s = stackinit();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    assert(pop(s) == 4);
    return 1;
}
int test2(){
    Stack * s = stackinit();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    int a, b, c;
    a = pop(s); b = pop(s); c = pop(s);
    assert( a * b + c == 14 && a * c + b == 11);
    return 1;
}
int test3(){
    Stack * s = stackinit();
    push(s,2);
    push(s,25);
    push(s,1);
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
