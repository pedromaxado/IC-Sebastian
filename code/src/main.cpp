#include <iostream>
#include <fstream>

#include "../include/Data.h"
#include "../include/Heap.h"
#include "../include/Alg1.h"
#include "../include/Alg2.h"
#include "../include/AlgT.h"
#include "../include/AlgQT.h"
#include "../include/AlgHeap.h"

#define MAXN 10000
#define PROB 10
#define REP  50

const string DATA_PATH = "../data/";
const string INST_PATH = "../instances/";

using namespace std;

double getElapsedTime( clock_t init, clock_t end ) {
    return (double) (end-init)*1000/CLOCKS_PER_SEC;
}

int main( int argc, char const *argv[] ) {

    int i, j;

    clock_t start, end;

    ofstream fp_stats;

    string  inst_fpath,
            stats_fpath = DATA_PATH + "stats.txt";

    fp_stats.open(stats_fpath);

    fp_stats << "Algoritmo Trivial" << endl;

    for ( i = 10; i < MAXN; i *= 10 ) {

        inst_fpath = INST_PATH + to_string(i) + ".txt";

        Data data = new_data( inst_fpath );

        start = clock();
        for ( j = 0; j < REP; j++ ) {
            srand(1);

            TrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), PROB );
        }
        end = clock();

        destroy_data( data );
    }

    fp_stats << "Algoritmo Quase Trivial" << endl;

    for ( i = 10; i < MAXN; i *= 10 ) {

        inst_fpath = INST_PATH + to_string(i) + ".txt";

        Data data = new_data( inst_fpath );

        start = clock();
        for ( j = 0; j < REP; j++ ) {
            srand(1);

            AlmostTrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), PROB );
        }
        end = clock();

        destroy_data( data );
    }

    fp_stats << "Algoritmo Diagonal" << endl;

    for ( i = 10; i < MAXN; i *= 10 ) {

        inst_fpath = INST_PATH + to_string(i) + ".txt";

        Data data = new_data( inst_fpath );

        start = clock();
        for ( j = 0; j < REP; j++ ) {
            srand(1);

            alg1_Prob( getVecX(data), getVecY(data), getSize(data), PROB );
        }
        end = clock();

        destroy_data( data );
    }

    fp_stats << "Algoritmo Contourline" << endl;

    for ( i = 10; i < MAXN; i *= 10 ) {

        inst_fpath = INST_PATH + to_string(i) + ".txt";

        Data data = new_data( inst_fpath );

        start = clock();
        for ( j = 0; j < REP; j++ ) {
            srand(1);

            alg2_Prob( getVecX(data), getVecY(data), getSize(data), PROB );
        }
        end = clock();

        destroy_data( data );
    }

    fp_stats.close();

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
