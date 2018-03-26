#ifndef _ALGT_H_
#define _ALGT_H_

#include <iostream>

using namespace std;

pair<int, int> TrivialAlg( long long int* vecX, long long int* vecY, bool** resultMtx, int n );

pair<int, int> TrivialAlg_Prob( long long int* vecX, long long int* vecY, int n, const int PROB, int a, int b, int c );

#endif
