#include <limits>
#include "../include/CompatFunction.h"
#include "../include/Alg1.h"
#include "../include/Data.h"

#define INF numeric_limits<int>::max()

using namespace std;

pair<int, int> alg1( int* vecX, int* vecY, bool** resultMtx, int n, int* bestAns ) {

	if ( f( resultMtx, 0, 0 ) )
		return make_pair(0,0);

	int i = 1;
	int best = INF;
	pair<int, int> best_pair;

	while ( i < n && best > ( vecX[i-1] + vecY[i-1] ) ) {

		pair<int, int> current_pair;
		int cost_sum;

		for ( int j = i; j < n; j++ ) {

			current_pair = make_pair(i-1, j);
			cost_sum = vecX[i-1] + vecY[j];

			if ( f( resultMtx, current_pair.first, current_pair.second ) && cost_sum < best ) {
				best = cost_sum;
				best_pair = current_pair;
			}

			current_pair = make_pair(j, i-1);
			cost_sum = vecX[j] + vecY[i-1];

			if ( f( resultMtx, current_pair.first, current_pair.second ) && cost_sum < best ) {
				best = cost_sum;
				best_pair = current_pair;
			}
		}

		current_pair = make_pair(i, i);
		cost_sum = vecX[i] + vecY[i];

		if ( f(resultMtx, current_pair.first, current_pair.second ) && cost_sum < best ) {
			best = cost_sum;
			best_pair = current_pair;
		}

		i++;
	}

	if ( best < INF ) {
        *bestAns = best;
        return best_pair;
    }
	else {
        *bestAns = -1;
        return make_pair(-1,-1);
    }
}

pair<int, int> alg1_Prob( int* vecX, int* vecY, int n, int* bestAns, const int PROB ) {

	if ( f_prob( PROB ) )
		return make_pair(0,0);

	int i = 1;
	int best = INF;
	pair<int, int> best_pair;

	while ( i < n && best > ( vecX[i-1] + vecY[i-1] ) ) {

		pair<int, int> current_pair;
		int cost_sum;

		for ( int j = i; j < n; j++ ) {

			current_pair = make_pair(i-1, j);
			cost_sum = vecX[i-1] + vecY[j];

			if ( f_prob( PROB ) && cost_sum < best ) {
				best = cost_sum;
				best_pair = current_pair;
			}

			current_pair = make_pair(j, i-1);
			cost_sum = vecX[j] + vecY[i-1];

			if ( f_prob( PROB ) && cost_sum < best ) {
				best = cost_sum;
				best_pair = current_pair;
			}
		}

		current_pair = make_pair(i, i);
		cost_sum = vecX[i] + vecY[i];

		if ( f_prob( PROB ) && cost_sum < best ) {
			best = cost_sum;
			best_pair = current_pair;
		}

		i++;
	}

	if ( best < INF ) {
        *bestAns = best;
        return best_pair;
    }
	else {
        *bestAns = -1;
        return make_pair(-1,-1);
    }
}

// int main() {
//
//     int best;
// 	Data data = new_data();
//
//    	pair< int, int > res = alg1	( getVecX(data),
// 								  getVecY(data),
// 								  getCompatibilityMtx(data),
// 								  getSize(data),
// 								  &best );
//
//    	cout << "x: " << res.first << " y: " << res.second << " min: " << best << endl;
//
// 	return 0;
// }
