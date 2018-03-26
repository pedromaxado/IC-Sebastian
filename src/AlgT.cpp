#include <limits>
#include "../include/CompatFunction.h"
#include "../include/AlgT.h"
#include "../include/Data.h"

#define INF numeric_limits<long long int>::max()

using namespace std;

pair<int, int> TrivialAlg( long long int* vecX, long long int* vecY, bool** resultMtx, int n ) {

	if ( f( resultMtx, 0, 0 ) )
		return make_pair(0,0);

	int i, j;
	long long int best = INF;
	pair<int,int> best_pair;

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			if ( f( resultMtx, i, j ) ) {
				if ( ( vecX[i] + vecY[j] ) < best ) {
					best = vecX[i] + vecY[j];
					best_pair = make_pair(i,j);
				}
			}
		}
	}

	if ( best < INF )
		return best_pair;
	else
		return make_pair(-1,-1);
}

pair<int, int> TrivialAlg_Prob( long long int* vecX, long long int* vecY, int n, const int PROB, int a, int b, int c ) {

	if ( f_prob( PROB, a, b, c, 0, 0 ) )
		return make_pair(0,0);

	int i, j;
	long long int best = INF;
	pair<int,int> best_pair;

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			if ( f_prob( PROB, a, b, c, i, j ) ) {
				if ( ( vecX[i] + vecY[j] ) < best ) {
					best = vecX[i] + vecY[j];
					best_pair = make_pair(i,j);
				}
			}
		}
	}

	if ( best < INF )
		return best_pair;
	else
		return make_pair(-1,-1);
}

// int main() {
//
// 	Data data = new_data();
//
//    	pair< int, int > res = TrivialAlg( getVecX(data),
// 									   getVecY(data),
// 									   getCompatibilityMtx(data),
// 									   getSize(data) );
//
//    	cout << "x: " << res.first << " y: " << res.second << endl;
//
// 	return 0;
// }
