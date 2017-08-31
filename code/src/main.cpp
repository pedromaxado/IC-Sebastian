#include <iostream>
#include <fstream>
#include <vector>

#include "../include/Data.h"
#include "../include/Heap.h"
#include "../include/Alg1.h"
#include "../include/Alg2.h"
#include "../include/AlgT.h"
#include "../include/AlgQT.h"
#include "../include/AlgHeapUtils.h"
#include "../include/AlgHeap.h"

#define MAXPROB 10
#define MINPROB 10000
#define MAXN    10000
#define REP     50

const string DATA_PATH = "./data/stats_";
const string INST_PATH = "./instances/";

using namespace std;

double getElapsedTime( clock_t start, clock_t end ) {
    return (double) (end-start)*1000/CLOCKS_PER_SEC;
}

int main() {

    // unsigned int hash[MAXN][MAXN];
    // Pair stack[2*MAXN];

    double exec_time;
    int n, r, prob;

    clock_t start, end;

    ofstream fp_stats_diagonal,
             fp_stats_contourl,
             fp_stats_atrivial,
             fp_stats_trivial;
            //  fp_stats_heap;

    string  inst_fpath;

    fp_stats_diagonal.open( DATA_PATH + "diagonal.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_contourl.open( DATA_PATH + "contourl.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_atrivial.open( DATA_PATH + "atrivial.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_trivial .open( DATA_PATH + "trivial.csv" , std::ofstream::out | std::ofstream::app );
    // fp_stats_heap    .open( DATA_PATH + "heap.csv"    , std::ofstream::out | std::ofstream::app );

    for ( prob = MAXPROB; prob <= MINPROB; prob *= 10 ) {

        cout << endl << "# Probabilidade = " << (double)1/prob << "%" << endl;

        fp_stats_diagonal << (double) 1/prob;
        fp_stats_contourl << (double) 1/prob;
        fp_stats_atrivial << (double) 1/prob;
        fp_stats_trivial  << (double) 1/prob;

        for ( n = 10; n <= MAXN; n *= 10 ) {
            cout << "\t> n = " << n << endl;

            inst_fpath = INST_PATH + to_string(n) + ".txt";

            Data data = new_data( inst_fpath, PROB_MOD );

            cout << "\t>> Trivial\t\t";
            start = clock();
            for ( r = 0; r < REP; r++ ) {
                cout << ".";
                srand(1);
                TrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << endl;

            exec_time = getElapsedTime( start, end ) / REP;
            fp_stats_trivial << "," << exec_time;

            cout << "\t>> Quase Trivial\t";
            start = clock();
            for ( r = 0; r < REP; r++ ) {
                cout << ".";
                srand(1);
                AlmostTrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << endl;

            exec_time = getElapsedTime( start, end ) / REP;
            fp_stats_atrivial << "," << exec_time;

            cout << "\t>> Diagonal\t\t";
            start = clock();
            for ( r = 0; r < REP; r++ ) {
                cout << ".";
                srand(1);
                Alg1_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << endl;

            exec_time = getElapsedTime( start, end ) / REP;
            fp_stats_diagonal << "," << exec_time;

            cout << "\t>> Contourline\t\t";
            start = clock();
            for ( r = 0; r < REP; r++ ) {
                cout << ".";
                srand(1);
                Alg2_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << endl;

            exec_time = getElapsedTime( start, end ) / REP;
            fp_stats_contourl << "," << exec_time;

            destroy_data( data );

            cout << endl;
        }

        fp_stats_diagonal << endl;
        fp_stats_contourl << endl;
        fp_stats_atrivial << endl;
        fp_stats_trivial  << endl;
        // fp_stats_heap     << endl;
    }

    fp_stats_diagonal.close();
    fp_stats_contourl.close();
    fp_stats_atrivial.close();
    fp_stats_trivial .close();
    // fp_stats_heap    .close();

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
