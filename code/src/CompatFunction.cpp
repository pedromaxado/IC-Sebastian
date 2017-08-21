#include <bits/stdc++.h>
#include "../include/CompatFunction.h"

bool f( bool** resultMtx, int ln, int col ) {
	return resultMtx[ln][col];
}

bool f_prob( const int PROB ) {
	return ( rand() % PROB ) == 1;
}
