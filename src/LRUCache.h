
typedef struct ValueNode ValueNode;

typedef struct LRUCache LRUCache;

LRUCache* lRUCacheCreate(int);
int lRUCacheGet(LRUCache*, int);
void lRUCachePut(LRUCache*, int, int);
void lRUCacheFree(LRUCache*);