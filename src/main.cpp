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

#define QUOTE '"'

#define SEED 43

const string DATA_PATH = "./data/";
const string INST_PATH = "./instances/";

using namespace std;

double getElapsedTime( clock_t start, clock_t end ) {
    return (double) (end-start)*1000/CLOCKS_PER_SEC;
}

void run_all( int max_prob, int min_prob, int MAXN, int rep, const int seed ) {
    unsigned int **hash;
    Pair stack[2*MAXN];
    heap h;

    hash = (unsigned int**) malloc( MAXN * sizeof(unsigned int*) );

    for ( int i = 0; i < MAXN; i++ )
        hash[i] = (unsigned int*) malloc ( MAXN * sizeof(int) );

    double exec_time;
    int n, r, prob;

    clock_t start, end;

    ofstream fp_stats_diagonal,
             fp_stats_contourl,
             fp_stats_atrivial,
             fp_stats_trivial,
             fp_stats_heap;

    string  inst_fpath;

    fp_stats_diagonal.open( DATA_PATH + "all/1000_rep/seed_" +to_string(seed) + "/diagonal.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_contourl.open( DATA_PATH + "all/1000_rep/seed_" +to_string(seed) + "/contourl.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_atrivial.open( DATA_PATH + "all/1000_rep/seed_" +to_string(seed) + "/atrivial.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_trivial .open( DATA_PATH + "all/1000_rep/seed_" +to_string(seed) + "/trivial.csv" , std::ofstream::out | std::ofstream::app );
    fp_stats_heap    .open( DATA_PATH + "all/1000_rep/seed_" +to_string(seed) + "/heap.csv"    , std::ofstream::out | std::ofstream::app );

    for ( prob = max_prob; prob <= min_prob; prob *= 10 ) {

        cout << endl << "# Probabilidade = " << (double)1/prob << "%" << endl;

        fp_stats_diagonal << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_contourl << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_atrivial << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_trivial  << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_heap     << QUOTE << (double) 1/prob << QUOTE;

        for ( n = 10; n <= MAXN; n *= 10 ) {
            cout << "\t> n = " << n << endl;

            inst_fpath = INST_PATH + to_string(n) + ".txt";

            Data data = new_data( inst_fpath, PROB_MOD );

            cout << "\t>> Trivial\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                TrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_trivial << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Quase Trivial\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                AlmostTrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_atrivial << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Diagonal\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                Alg1_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_diagonal << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Contourline\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                Alg2_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_contourl << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Heap\t\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                AlgHeap_Prob( getSize(data), getVecX(data), getVecY(data), prob, h, stack, hash );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_heap << "," << QUOTE << exec_time << QUOTE;

            destroy_data( data );

            cout << endl;
        }

        fp_stats_diagonal << endl;
        fp_stats_contourl << endl;
        fp_stats_atrivial << endl;
        fp_stats_trivial  << endl;
        fp_stats_heap     << endl;
    }

    fp_stats_diagonal.close();
    fp_stats_contourl.close();
    fp_stats_atrivial.close();
    fp_stats_trivial .close();
    fp_stats_heap    .close();

    for ( int i = 0; i < MAXN; i++ ) {
        free(hash[i]);
    }

    free(hash);
}

void run_triv_vs_atriv( int max_prob, int min_prob, int MAXN, int rep, const int seed ) {

    double exec_time;
    int n, r, prob;

    clock_t start, end;

    ofstream fp_stats_trivial,
             fp_stats_atrivial;

    string  inst_fpath;

    fp_stats_atrivial.open( DATA_PATH + "triv_vs_atriv/" + "seed_" + to_string(seed) + "/atrivial.csv",
                            std::ofstream::out | std::ofstream::app );
    fp_stats_trivial .open( DATA_PATH + "triv_vs_atriv/" + "seed_" + to_string(seed) + "/trivial.csv" ,
                            std::ofstream::out | std::ofstream::app );

    for ( prob = max_prob; prob <= min_prob; prob *= 10 ) {

        cout << endl << "# Probabilidade = " << (double)1/prob << "%" << endl;

        fp_stats_atrivial << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_trivial  << QUOTE << (double) 1/prob << QUOTE;

        for ( n = 10; n <= MAXN; n *= 10 ) {

            cout << "\t> n = " << n << endl;

            inst_fpath = INST_PATH + to_string(n) + ".txt";

            Data data = new_data( inst_fpath, PROB_MOD );

            cout << "\t>> Trivial\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                TrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_trivial << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Quase Trivial\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                AlmostTrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_atrivial << "," << QUOTE << exec_time << QUOTE;

            destroy_data( data );

            cout << endl;
        }

        fp_stats_atrivial << endl;
        fp_stats_trivial  << endl;
    }

    fp_stats_atrivial.close();
    fp_stats_trivial .close();
}

int main() {

    int max_prob = 10;
    int min_prob = 10000;
    int MAXN     = 10000;
    int rep      = 1000;

    for ( int seed = 1; seed <= 1; seed++ ) {
        cout << "SEED " << seed << endl;
        run_all( max_prob, min_prob, MAXN, rep, seed );
    }

    printf("\n\n\n FINISHED ALL ALGORITHMS\n");

    //max_prob = 10000;
    //min_prob = 10000000;

    //for ( int seed = 1; seed <= 50; seed++ ) {
    //    cout << "SEED " << seed << endl;
    //    run_triv_vs_atriv( max_prob, min_prob, MAXN, rep, seed );
    //}

    //printf("\n\n\n FINISHED TRIV VS ATRIV\n");

	// Data data = new_data( "./instances/15.txt", MTX_MOD );
    //
    // pair< int, int > res;
    // res = Alg1	( getVecX(data),
    // 			  getVecY(data),
    // 			  getCompatibilityMtx(data),
    // 			  getSize(data) );
    //
    // printf("%d %d\n", res.first, res.second );
    //
    // res = Alg2	( getVecX(data),
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
    //                     &minb,
    //                     h, stack, hash );
    //
    // printf("%d %d\n", mina, minb);
    //
    // destroy_data(data);
    //
    // for ( int i = 0; i < MAXN; i++ ) {
    //     free(hash[i]);
    // }
    //
    // free(hash);

    return 0;
}
