#include <limits>
#include "../include/CompatFunction.h"
#include "../include/AlgQT.h"
#include "../include/Data.h"

#define INF numeric_limits<long long int>::max()

using namespace std;

pair<int, int> AlmostTrivialAlg( long long int* vecX, long long int* vecY, bool** resultMtx, int n ) {

	if ( f( resultMtx, 0, 0 ) )
		return make_pair(0,0);

	int ln = 0, col = 0, maxCol = n;
	// long long int best = INF;
	pair<int, int> best_pair;

	while ( ln < n && maxCol > 0 ) {

		for ( col = 0; col < maxCol; col++ ) {
			if ( f( resultMtx, ln, col ) ) {
				// best = vecX[ln] + vecY[col];
				best_pair = make_pair(ln, col);

				maxCol = col;
			}
		}

		ln++;
	}

	return best_pair;
}

pair<int, int> AlmostTrivialAlg_Prob( long long int* vecX, long long int* vecY, int n, const int PROB, int a, int b, int c ) {

	if ( f_prob( PROB, a, b, c, 0, 0 ) )
		return make_pair(0,0);

	int ln = 0, col = 0, maxCol = n;
	// long long int best = INF;
	pair<int, int> best_pair;

	while ( ln < n && maxCol > 0 ) {

		for ( col = 0; col < maxCol; col++ ) {
			// if ( f_prob( PROB ) ) {
			if ( f_prob( PROB, a, b, c, ln, col ) ) {
				// best = vecX[ln] + vecY[col];
				best_pair = make_pair(ln, col);

				maxCol = col;
			}
		}

		ln++;
	}

	return best_pair;
}

// int main() {
//
// 	Data data = new_data();
//
//    	pair< int, int > res = AlmostTrivialAlg	( getVecX(data),
// 											  getVecY(data),
// 											  getCompatibilityMtx(data),
// 											  getSize(data) );
//
//    	cout << "x: " << res.first << " y: " << res.second << endl;
//
// 	return 0;
// }
