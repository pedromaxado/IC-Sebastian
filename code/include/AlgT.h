#ifndef _ALGT_H_
#define _ALGT_H_

#include <iostream>

using namespace std;

pair<int, int> TrivialAlg( int* vecX, int* vecY, bool** resultMtx, int n );

pair<int, int> TrivialAlg_Prob( int* vecX, int* vecY, int n, const int PROB );

#endif
