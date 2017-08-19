#include <bits/stdc++.h>
#include "../include/CompatFunction.h"
#include "../include/Alg2.h"
#include "../include/Data.h"

#define RESOURCES 10
#define INF numeric_limits<int>::max()

using namespace std;

pair<int, int> alg2( int* vecX, int* vecY, bool** resultMtx, int n ) {

	int i = 0, j;
	int best = INF;
	pair<int,int> best_pair = make_pair(-1,-1);
	vector<int> contourline(n);

	for ( j = 0; j < n; j++ )
		contourline[j] = 1;

	while ( i < n && best == INF ) {

		for ( j = 0; j < n; j++ ) {

			int sum = vecX[j] + vecY[contourline[j]];

			while ( contourline[j] < n && sum <= (vecX[i] + vecY[i]) ) {
				if ( f(resultMtx, j, contourline[j]) == 1 && sum < best ) {
					best = sum;
					best_pair = make_pair(j, contourline[j]);
				}

				contourline[j]++;
			}
		}

		i++;
	}

	return best_pair;
}

int main() {

	Data data = new_data();

   	pair< int, int > res = alg2	( getVecX(data),
								  getVecY(data),
								  getCompatibilityMtx(data),
								  getSize(data) );

   	cout << "x: " << res.first << " y: " << res.second << endl;

	return 0;
}
