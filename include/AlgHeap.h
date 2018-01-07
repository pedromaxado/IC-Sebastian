#ifndef _ALGHEAP_H_
#define _ALGHEAP_H_

// #include <iostream>
// #include "Heap.h"

// using namespace std;

// pair<int, int> AlgHeap( int n, int* vecX, int* vecY, bool** resultMtx, Heap h, int** hash );

// pair<int, int> AlgHeap_Prob( int n, int* vecX, int* vecY, const int PROB, Heap h, int** hash );

#include "AlgHeapUtils.h"

int AlgHeap( int n, int *vecX, int *vecY, bool **mtx, int* mina, int* minb, heap h, Pair *stack, unsigned int **hash );

int AlgHeap_Prob( int n, int *vecX, int *vecY, const int PROB, heap h, Pair *stack, unsigned int **hash );

#endif