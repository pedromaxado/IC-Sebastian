#ifndef _ALGHEAPUTILS_H_
#define _ALGHEAPUTILS_H_

#define MAX 10100

typedef struct {
    int sum;
    int aind;
    int bind;
} Pair;

typedef struct {
    Pair data[2*MAX];
    int size;
} heap;

#endif
