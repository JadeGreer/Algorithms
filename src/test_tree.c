#include "tree.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


int test0(){
    char* c = "";
    Tree* T = tree_init(c);
    assert(tree_length(T) == 0);
    return 1;
}

int test1(){
    char* c = "22+";
    Tree* T = tree_init(c);
    assert (tree_length(T) == 2);
    return 1;
}

int test2(){
    char* c = "123+45**6+*";
    Tree* T = tree_init(c);
    assert(tree_length(T) == 5);
    return 1 ;
}

int main() {
    assert(test0() && test1() && test2()); //  
    printf("Your trees are all good! \n");
    return 0;
}