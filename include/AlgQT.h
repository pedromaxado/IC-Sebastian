#ifndef _ALGQT_H_
#define _ALGQT_H_

#include <iostream>

using namespace std;

pair<int, int> AlmostTrivialAlg( long long int* vecX, long long int* vecY, bool** resultMtx, int n );

pair<int, int> AlmostTrivialAlg_Prob( long long int* vecX, long long int* vecY, int n, const int PROB, int a, int b, int c );

#endif
