#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"


int test1() {
    Queue * q = queue_init();
    put(q,'B');
    get(q);
    assert(is_empty(q));
    return 1;
}

int test2() {
    Queue * q = queue_init();
    put(q,2);
    assert(!is_empty(q));
    put(q,1);
    int a, b;
    a = get(q); b = get(q);
    assert(a+b == 3);
    return 1; 
}


int test3() {
    Queue * q = queue_init();
    put(q,2);
    put(q,3);
    int a, b;
    a = get(q); b = get(q);
    assert(a*b == 6);
    return 1;
};
int test4() {
    Queue * q = queue_init();
    put(q,2);
    put(q,25);
    put(q,1);
    get(q);
    get(q);
    assert(!is_empty(q));
    get(q);
    assert(is_empty(q));
    return 1;
};


int main() {
    assert(test1() && test2() && test3() && test4());
    printf("All good! \n");
    return 0;
}