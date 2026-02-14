#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *keys;
    int *vals;
    int cap;
    int size;
} HashMap;

static void hmInit(HashMap *hm, int cap)
{
    hm->cap = cap < 16 ? 16 : cap;
    hm->size = 0;
    hm->keys = (int *)malloc(sizeof(int) * hm->cap);
    hm->vals = (int *)malloc(sizeof(int) * hm->cap);
    memset(hm->keys, -1, sizeof(int) * hm->cap);
}

static void hmFree(HashMap *hm)
{
    free(hm->keys);
    free(hm->vals);
}

static void hmClear(HashMap *hm)
{
    hm->size = 0;
    memset(hm->keys, -1, sizeof(int) * hm->cap);
}

static int hmGet(HashMap *hm, int key, int defaultVal)
{
    int idx = (unsigned)key % hm->cap;
    while (hm->keys[idx] != -1)
    {
        if (hm->keys[idx] == key)
            return hm->vals[idx];
        idx = (idx + 1) % hm->cap;
    }
    return defaultVal;
}

static void hmPut(HashMap *hm, int key, int val)
{
    int idx = (unsigned)key % hm->cap;
    while (hm->keys[idx] != -1 && hm->keys[idx] != key)
        idx = (idx + 1) % hm->cap;
    if (hm->keys[idx] == -1)
        hm->size++;
    hm->keys[idx] = key;
    hm->vals[idx] = val;
}

typedef struct
{
    int n, total, origTotal;
    HashMap map;
} Solution;

Solution *solutionCreate(int m, int n)
{
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->n = n;
    obj->total = m * n;
    obj->origTotal = m * n;

    hmInit(&obj->map, 4096);
    return obj;
}

int *solutionFlip(Solution *obj, int *retSize)
{
    int r = rand() % obj->total;

    int valR = hmGet(&obj->map, r, r);
    int valLast = hmGet(&obj->map, obj->total - 1, obj->total - 1);

    hmPut(&obj->map, r, valLast);

    obj->total--;

    int *ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = valR / obj->n;
    ret[1] = valR % obj->n;
    *retSize = 2;
    return ret;
}

void solutionReset(Solution *obj)
{
    obj->total = obj->origTotal;
    hmClear(&obj->map);
}

void solutionFree(Solution *obj)
{
    hmFree(&obj->map);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(m, n);
 * int* param_1 = solutionFlip(obj, retSize);

 * solutionReset(obj);

 * solutionFree(obj);
*/