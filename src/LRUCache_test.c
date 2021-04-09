#include "LRUCache.h"
#include <stdio.h>
#include <assert.h>

int test1(){
    LRUCache* lRU = lRUCacheCreate(2);
    lRUCachePut(lRU, 1, 1); // cache is {1=1}
    lRUCachePut(lRU, 2, 2); // cache is {1=1, 2=2}
    int n = lRUCacheGet(lRU, 1);    // return 1
    assert(n == 1);
    lRUCachePut(lRU, 3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    n = lRUCacheGet(lRU, 2);    // returns -1 (not found)
    assert(n == -1);
    lRUCachePut(lRU, 4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    n = lRUCacheGet(lRU, 1);    // return -1 (not found)
    assert(n == -1);
    n = lRUCacheGet(lRU, 3);    // return 3
    assert(n == 3);
    n = lRUCacheGet(lRU, 4);  // return 4
    assert(n == 4);
    return 1;
}

int test2(){
    LRUCache* lRU = lRUCacheCreate(1);
    lRUCachePut(lRU, 2, 1); // cache is {2=1}
    int n = lRUCacheGet(lRU, 2);    // return 1
    assert(n == 1);
    lRUCachePut(lRU, 3, 2); // cache is {3=2}
    n = lRUCacheGet(lRU, 2);    // return -1
    assert(n == -1);
    n = lRUCacheGet(lRU, 3);    // return 2
    assert(n == 2);
    lRUCacheFree(lRU);
    return 1;
}

int test3(){ 
    printf("here\n");   
    LRUCache* lRU = lRUCacheCreate(2);
    lRUCachePut(lRU, 2, 1);
    printcache(lRU);
    lRUCachePut(lRU, 1, 1);
    printcache(lRU);
    lRUCachePut(lRU, 2, 3);
    printcache(lRU);
    lRUCachePut(lRU, 4, 1);
    printcache(lRU);
    int n = lRUCacheGet(lRU, 1);  
    assert(n == -1);
    n = lRUCacheGet(lRU, 2);  
    assert(n == 3);

    lRUCacheFree(lRU);
    return 1;
}

int main() {
    if (test3()) printf("All tests passed!\n");
    return 1;
}

