#include <iostream>
#include <fstream>
#include <vector>

#include "../include/Data.h"
#include "../include/Heap.h"
#include "../include/Alg1.h"
#include "../include/Alg2.h"
#include "../include/AlgT.h"
#include "../include/AlgQT.h"
#include "../include/AlgHeap.h"

#define MINPROB 10000
#define MAXN    10
#define REP     50

const string DATA_PATH = "./data/stats_";
const string INST_PATH = "./instances/";

using namespace std;

double getElapsedTime( clock_t start, clock_t end ) {
    return (double) (end-start)*1000/CLOCKS_PER_SEC;
}

int main() {

    double exec_time;
    int n, r, prob;

    clock_t start, end;

    ofstream fp_stats_diagonal,
             fp_stats_contourl,
             fp_stats_atrivial,
             fp_stats_trivial,
             fp_stats_heap;

    string  inst_fpath;

    fp_stats_diagonal.open( DATA_PATH + "diagonal.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_contourl.open( DATA_PATH + "contourl.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_atrivial.open( DATA_PATH + "atrivial.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_trivial .open( DATA_PATH + "trivial.csv" , std::ofstream::out | std::ofstream::app );
    fp_stats_heap    .open( DATA_PATH + "heap.csv"    , std::ofstream::out | std::ofstream::app );

    for ( prob = 10; prob <= MINPROB; prob *= 10 ) {

        fp_stats_diagonal << "P = " << prob << endl;
        fp_stats_contourl << "P = " << prob << endl;
        fp_stats_atrivial << "P = " << prob << endl;
        fp_stats_trivial  << "P = " << prob << endl;

        for ( n = 10; n <= MAXN; n *= 10 ) {
            inst_fpath = INST_PATH + to_string(n) + ".txt";

            Data data = new_data( inst_fpath, PROB_MOD );

            start = clock();
            for ( r = 0; r < REP; r++ ) {
                TrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();

            exec_time = getElapsedTime( start, end ) / REP;

            fp_stats_trivial << n << "," << exec_time << endl;

            start = clock();
            for ( r = 0; r < REP; r++ ) {
                AlmostTrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();

            exec_time = getElapsedTime( start, end ) / REP;

            fp_stats_atrivial << n << "," << exec_time << endl;

            start = clock();
            for ( r = 0; r < REP; r++ ) {
                Alg1_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();

            exec_time = getElapsedTime( start, end ) / REP;

            fp_stats_diagonal << n << "," << exec_time << endl;

            start = clock();
            for ( r = 0; r < REP; r++ ) {
                Alg2_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();

            exec_time = getElapsedTime( start, end ) / REP;

            fp_stats_contourl << n << "," << exec_time << endl;

            destroy_data( data );
        }
    }

    fp_stats_diagonal.close();
    fp_stats_contourl.close();
    fp_stats_atrivial.close();
    fp_stats_trivial .close();
    fp_stats_heap    .close();

	// Data data = new_data( "./instancias/15.txt", MTX_MOD );
    //
    // pair< int, int > res;
    // res = alg1	( getVecX(data),
    // 			  getVecY(data),
    // 			  getCompatibilityMtx(data),
    // 			  getSize(data) );
    //
    // printf("%d %d\n", res.first, res.second );
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
    // int mina, minb;
    //
    // int sum = AlgHeap ( getSize(data),
    //                     getVecX(data),
    // 				    getVecY(data),
    // 				    getCompatibilityMtx(data),
    //                     &mina,
    //                     &minb );
    //
    // printf("%d %d\n", mina, minb);
    //
    // destroy_data(data);

    return 0;
}
