#include <limits>
#include "../include/CompatFunction.h"
#include "../include/Alg1.h"
#include "../include/Data.h"

#define INF numeric_limits<long long int>::max()

using namespace std;

pair<int, int> Alg1( long long int* vecX, long long int* vecY, bool** resultMtx, int n ) {

	if ( f( resultMtx, 0, 0 ) )
		return make_pair(0,0);

	int i = 1;
	long long int best = INF;
	pair<int, int> best_pair;

	while ( i < n && best > ( vecX[i-1] + vecY[i-1] ) ) {

		pair<int, int> current_pair;
		long long int cost_sum;

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

	if ( best < INF )
        return best_pair;
	else
        return make_pair(-1,-1);
}

pair<int, int> Alg1_Prob( long long int* vecX, long long int* vecY, int n, const int PROB ) {

	if ( f_prob( PROB ) )
		return make_pair(0,0);

	int i = 1;
	long long int best = INF;
	pair<int, int> best_pair;

	while ( i < n && best > ( vecX[i-1] + vecY[i-1] ) ) {

		pair<int, int> current_pair;
		long long int cost_sum;

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

	if ( best < INF )
        return best_pair;
	else
        return make_pair(-1,-1);
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
