#include <iostream>
#include "../include/Data.h"
#include "../include/Heap.h"
#include "../include/Alg1.h"
#include "../include/Alg2.h"
#include "../include/AlgT.h"
#include "../include/AlgQT.h"
#include "../include/AlgHeap.h"

#define MAXN 10000
#define PROB 10
#define REP 30

using namespace std;

double getElapsedTime( clock_t init, clock_t end ) {
    return (double) (end-init)*1000/CLOCKS_PER_SEC;
}

int main( int argc, char const *argv[] ) {

    FILE* fp;
    clock_t start, end;
    double sumTriv, sumATriv, sumAlg1, sumAlg2;

    fp = fopen("../data/stats.dat", "w");

    if ( fp == NULL ) {
        printf("Erro na abertura de arquivo\n");
        exit(EXIT_FAILURE);
    }

    pair<int,int> res;

    for ( int n = 10; n <= MAXN; n *= 10 ) {
        sumTriv = sumATriv = sumAlg1 = sumAlg2 = 0;
        for ( int j = 0; j < REP; j++ ) {
            srand(1);

            start = clock();
            TrivialAlg_Prob(n, getVecX(data), getVecY(data), PROB);
            end = clock();

            sumTriv += getElapsedTime(start, end);

            srand(1);

            start = clock();
            AlmostTrivialAlg_Prob(n, getVecX(data), getVecY(data), PROB);
            end = clock();

            sumATriv += getElapsedTime(start, end);

            srand(1);

            start = clock();
            alg1_Prob(n, getVecX(data), getVecY(data), PROB);
            end = clock();

            sumAlg1 += getElapsedTime(start, end);

            srand(1);

            start = clock();
            alg2_Prob(n, getVecX(data), getVecY(data), PROB);
            end = clock();

            sumAlg2 += getElapsedTime(start, end);
        }

        sumTriv /= REP;
        sumATriv /= REP;
        sumAlg1 /= REP;
        sumAlg2 /= REP;

        fprintf(fp, "Trivial n = %d\n", n);
        fprintf(fp, "%lf\n\n", sumTriv);

        fprintf(fp, "Quase Trivial n = %d\n", n);
        fprintf(fp, "%lf\n\n", sumATriv);

        fprintf(fp, "Alg 1 n = %d\n", n);
        fprintf(fp, "%lf\n\n", sumAlg1);

        fprintf(fp, "Alg 2 n = %d\n", n);
        fprintf(fp, "%lf\n\n", sumAlg2);
    }

    fclose(fp);

    // int best;
	// Data data = new_data();
    // pair< int, int > res;
    // res = alg1	( getVecX(data),
    // 			  getVecY(data),
    // 			  getCompatibilityMtx(data),
    // 			  getSize(data),
    // 			  &best );
    //
    // printf("%d %d\n", res.first, res.second);
    //
    // res = alg2	( getVecX(data),
	// 			  getVecY(data),
	// 			  getCompatibilityMtx(data),
	// 			  getSize(data) );
    //
    // printf("%d %d\n", res.first, res.second);
    //
    // res = TrivialAlg ( getVecX(data),
    //         		   getVecY(data),
    //         		   getCompatibilityMtx(data),
    //         		   getSize(data) );
    //
    // printf("%d %d\n", res.first, res.second);
    //
    // res = AlmostTrivialAlg	( getVecX(data),
    //         				  getVecY(data),
    //         				  getCompatibilityMtx(data),
    //         				  getSize(data) );
    //
    // printf("%d %d\n", res.first, res.second);
    //
    // destroy_data(data);

    return 0;
}
