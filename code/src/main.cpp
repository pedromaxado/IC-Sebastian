#include <bits/stdc++.h>
#include "../include/Data.h"
#include "../include/Alg1.h"
#include "../include/Alg2.h"
#include "../include/AlgT.h"
#include "../include/AlgQT.h"
#include "../include/AlgHeap.h"

using namespace std;

double getElapsedTime( clock_t init, clock_t end ) {
    return (double) (end-init)*1000/CLOCKS_PER_SEC;
}

int main( int argc, char const *argv[] ) {

    int best;
	Data data = new_data();
    pair< int, int > res;
    res = alg1	( getVecX(data),
    			  getVecY(data),
    			  getCompatibilityMtx(data),
    			  getSize(data),
    			  &best );

    printf("%d %d", res.first, res.second);

    res = alg2	( getVecX(data),
				  getVecY(data),
				  getCompatibilityMtx(data),
				  getSize(data) );

    printf("%d %d", res.first, res.second);

    res = TrivialAlg ( getVecX(data),
            		   getVecY(data),
            		   getCompatibilityMtx(data),
            		   getSize(data) );

    printf("%d %d", res.first, res.second);

    res = AlmostTrivialAlg	( getVecX(data),
            				  getVecY(data),
            				  getCompatibilityMtx(data),
            				  getSize(data) );

    printf("%d %d", res.first, res.second);

    return 0;
}
