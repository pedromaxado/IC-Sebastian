#ifndef _ALGQT_H_
#define _ALGQT_H_

#include <iostream>

using namespace std;

pair<int, int> AlmostTrivialAlg( int* vecX, int* vecY, bool** resultMtx, int n );

pair<int, int> AlmostTrivialAlg_Prob( int* vecX, int* vecY, int n, const int PROB );

#endif
