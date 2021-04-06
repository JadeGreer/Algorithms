#include "LRUCache.h"
#include <stdio.h>


int main() {
    LRUCache* lRU = lRUCacheCreate(2);
    lRUCachePut(lRU, 1, 1); // cache is {1=1}
    lRUCachePut(lRU, 2, 2); // cache is {1=1, 2=2}
    lRUCacheGet(lRU, 1);    // return 1
    lRUCachePut(lRU, 3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCacheGet(lRU, 2);    // returns -1 (not found)
    lRUCachePut(lRU, 4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCacheGet(lRU, 1);    // return -1 (not found)
    lRUCacheGet(lRU, 3);    // return 3
    printf("%d\n",lRUCacheGet(lRU, 4));  // return 4

};
