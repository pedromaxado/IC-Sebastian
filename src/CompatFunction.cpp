#include <iostream>
#include <cstdlib>
#include "../include/CompatFunction.h"

bool f( bool** resultMtx, int ln, int col ) {
	return resultMtx[ln][col];
}

// bool f_prob( const int PROB ) {
// 	return ( rand() % PROB ) == 1;
// }

bool f_prob( const int PROB ) {

   for ( int i = 0; i < DELAY; i++ ) {
       rand();
   }

   return ( rand() % PROB ) == 1;
}
