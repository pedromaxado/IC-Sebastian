#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "../include/Data.h"
#include "../include/Heap.h"
#include "../include/Alg1.h"
#include "../include/Alg2.h"
#include "../include/AlgT.h"
#include "../include/AlgQT.h"
#include "../include/AlgHeapUtils.h"
#include "../include/AlgHeap.h"

#define QUOTE '"'

#define SEED 50

string DATA_PATH;
string INST_PATH;

unsigned int NPRIMES;
vector<int> primes;

using namespace std;

double getElapsedTime( clock_t start, clock_t end ) {
    return (double) (end-start)*1000/CLOCKS_PER_SEC;
}

void run( int max_prob, int min_prob, int MAXN, int rep, const int seed ) {

    heap h;

    double exec_time;
    int n, r, prob;

    clock_t start, end;

    ofstream fp_stats_diagonal,
             fp_stats_contourl,
             fp_stats_atrivial,
             fp_stats_heap;

    string  inst_fpath;

    fp_stats_diagonal.open( DATA_PATH + "seed_" +to_string(seed) + "/diagonal.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_contourl.open( DATA_PATH + "seed_" +to_string(seed) + "/contourl.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_atrivial.open( DATA_PATH + "seed_" +to_string(seed) + "/atrivial.csv", std::ofstream::out | std::ofstream::app );
    fp_stats_heap    .open( DATA_PATH + "seed_" +to_string(seed) + "/heap.csv"    , std::ofstream::out | std::ofstream::app );

    for ( prob = max_prob; prob <= min_prob; prob *= 10 ) {

        cout << endl << "# Probabilidade = " << (double)1/prob << "%" << endl;

        fp_stats_diagonal << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_contourl << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_atrivial << QUOTE << (double) 1/prob << QUOTE;
        fp_stats_heap     << QUOTE << (double) 1/prob << QUOTE;

        for ( n = 10; n <= MAXN; n *= 10 ) {
            cout << "\t> n = " << n << endl;

            inst_fpath = INST_PATH + to_string(n) + ".txt";

            Data data = new_data( inst_fpath, PROB_MOD );

            cout << "\t>> Quase Trivial\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                int x = rand() % NPRIMES;
                int a = primes[x];
                int y = rand() % NPRIMES;
                int b = primes[y];
                int z = rand() % NPRIMES;
                int c = primes[z];
                AlmostTrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob, a, b, c );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_atrivial << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Diagonal\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                int x = rand() % NPRIMES;
                int a = primes[x];
                int y = rand() % NPRIMES;
                int b = primes[y];
                int z = rand() % NPRIMES;
                int c = primes[z];
                Alg1_Prob( getVecX(data), getVecY(data), getSize(data), prob, a, b, c );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_diagonal << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Contourline\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                int x = rand() % NPRIMES;
                int a = primes[x];
                int y = rand() % NPRIMES;
                int b = primes[y];
                int z = rand() % NPRIMES;
                int c = primes[z];
                Alg2_Prob( getVecX(data), getVecY(data), getSize(data), prob, a, b, c );
            }
            end = clock();
            cout << "Done" << endl;

            exec_time = getElapsedTime( start, end ) / rep;
            fp_stats_contourl << "," << QUOTE << exec_time << QUOTE;

            cout << "\t>> Heap\t\t\t";
            srand(SEED);
            start = clock();
            for ( r = 0; r < rep; r++ ) {
                int x = rand() % NPRIMES;
                int a = primes[x];
                int y = rand() % NPRIMES;
                int b = primes[y];
                int z = rand() % NPRIMES;
                int c = primes[z];
                AlgHeap_Prob( getSize(data), getVecX(data), getVecY(data), prob, h, a, b, c );
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
        fp_stats_heap     << endl;
    }

    fp_stats_diagonal.close();
    fp_stats_contourl.close();
    fp_stats_atrivial.close();
    fp_stats_heap    .close();
}

// void run_triv_vs_atriv( int max_prob, int min_prob, int MAXN, int rep, const int seed ) {

//     double exec_time;
//     int n, r, prob;

//     clock_t start, end;

//     ofstream fp_stats_trivial,
//              fp_stats_atrivial;

//     string  inst_fpath;

//     fp_stats_atrivial.open( DATA_PATH + "triv_vs_atriv/" + "seed_" + to_string(seed) + "/atrivial.csv",
//                             std::ofstream::out | std::ofstream::app );
//     fp_stats_trivial .open( DATA_PATH + "triv_vs_atriv/" + "seed_" + to_string(seed) + "/trivial.csv" ,
//                             std::ofstream::out | std::ofstream::app );

//     for ( prob = max_prob; prob <= min_prob; prob *= 10 ) {

//         cout << endl << "# Probabilidade = " << (double)1/prob << "%" << endl;

//         fp_stats_atrivial << QUOTE << (double) 1/prob << QUOTE;
//         fp_stats_trivial  << QUOTE << (double) 1/prob << QUOTE;

//         for ( n = 10; n <= MAXN; n *= 10 ) {

//             cout << "\t> n = " << n << endl;

//             inst_fpath = INST_PATH + to_string(n) + ".txt";

//             Data data = new_data( inst_fpath, PROB_MOD );

//             cout << "\t>> Trivial\t\t";
//             srand(SEED);
//             start = clock();
//             for ( r = 0; r < rep; r++ ) {
//                 TrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
//             }
//             end = clock();
//             cout << "Done" << endl;

//             exec_time = getElapsedTime( start, end ) / rep;
//             fp_stats_trivial << "," << QUOTE << exec_time << QUOTE;

//             cout << "\t>> Quase Trivial\t";
//             srand(SEED);
//             start = clock();
//             for ( r = 0; r < rep; r++ ) {
//                 AlmostTrivialAlg_Prob( getVecX(data), getVecY(data), getSize(data), prob );
//             }
//             end = clock();
//             cout << "Done" << endl;

//             exec_time = getElapsedTime( start, end ) / rep;
//             fp_stats_atrivial << "," << QUOTE << exec_time << QUOTE;

//             destroy_data( data );

//             cout << endl;
//         }

//         fp_stats_atrivial << endl;
//         fp_stats_trivial  << endl;
//     }

//     fp_stats_atrivial.close();
//     fp_stats_trivial .close();
// }

int sieve( int n, vector<int>& primes ) {

    vector<int> p(n);

    for ( int i = 0; i < n; i++ ) {
        p[i] = 1;
    }

    p[0] = p[1] = 0;

    for ( int j = 2; j < sqrt(n); j++ ) {
        if ( p[j] ) {
            for ( int k = j*j; k < n; k += j ) {
                p[k] = 0;
            }
        }
    }

    for ( int a = 0; a < n; a++ )
        if ( p[a] )
            primes.push_back(a);

    return primes.size();
}

int main() {

    int max_prob = 10;
    int min_prob = 100000;
    int MAXN     = 100000;
    int rep      = 100;

    NPRIMES = sieve(1000000, primes);

    // cout << NPRIMES << endl;

    // for ( unsigned int k = 0; k < primes.size(); k++ )
    //     printf("%d ", primes[k]);

    // cout << endl;

    // Simple(linear) distribution with simple compat function
    DATA_PATH = "./data/simple_dist/simple/";
    INST_PATH = "./instances/simple_dist/";

    for ( int seed = 1; seed <= SEED; seed++ ) {
        cout << "SEED " << seed << endl;
        run( max_prob, min_prob, MAXN, rep, seed );
    }

    // Big difference(crappy name) distribution with simple compat function
    DATA_PATH = "./data/bigdif_dist/simple/";
    INST_PATH = "./instances/bigdif_dist/";

    for ( int seed = 1; seed <= SEED; seed++ ) {
        cout << "SEED " << seed << endl;
        run( max_prob, min_prob, MAXN, rep, seed );
    }

    // "Exponencial" distribution with simple compat function
    // DATA_PATH = "./data/exp_dist/simple/";
    // INST_PATH = "./instances/exp_dist/";

    // for ( int seed = 1; seed <= SEED; seed++ ) {
    //     cout << "SEED " << seed << endl;
    //     run( max_prob, min_prob, MAXN, rep, seed );
    // }

    // Simple(linear) distribution with heavy compat function
    DATA_PATH = "./data/simple_dist/heavy/";
    INST_PATH = "./instances/simple_dist/";

    for ( int seed = 1; seed <= SEED; seed++ ) {
        cout << "SEED " << seed << endl;
        run( max_prob, min_prob, MAXN, rep, seed );
    }

    // Big difference(crappy name) distribution with heavy compat function
    DATA_PATH = "./data/bigdif_dist/heavy/";
    INST_PATH = "./instances/bigdif_dist/";

    for ( int seed = 1; seed <= SEED; seed++ ) {
        cout << "SEED " << seed << endl;
        run( max_prob, min_prob, MAXN, rep, seed );
    }

    // "Exponencial" distribution with heavy compat function
    // DATA_PATH = "./data/exp_dist/heavy/";
    // INST_PATH = "./instances/exp_dist/";

    // for ( int seed = 1; seed <= SEED; seed++ ) {
    //     cout << "SEED " << seed << endl;
    //     run( max_prob, min_prob, MAXN, rep, seed );
    // }

    printf("\n\nFINISHED\n");

    // Data data = new_data( "15.txt", MTX_MOD );
    
    // pair< int, int > res;
    // res = Alg1       ( getVecX(data),
    //                    getVecY(data),
    //                    getCompatibilityMtx(data),
    //                    getSize(data) );
    
    // printf("%d %d\n", res.first, res.second );
    
    // res = Alg2       ( getVecX(data),
    //                            getVecY(data),
    //                            getCompatibilityMtx(data),
    //                            getSize(data) );
    
    // printf("%d %d\n", res.first, res.second);
    
    // res = TrivialAlg ( getVecX(data),
    //                     getVecY(data),
    //                     getCompatibilityMtx(data),
    //                     getSize(data) );
    
    // printf("%d %d\n", res.first, res.second);
    
    // res = AlmostTrivialAlg   ( getVecX(data),
    //                                    getVecY(data),
    //                                    getCompatibilityMtx(data),
    //                                    getSize(data) );
    
    // printf("%d %d\n", res.first, res.second);
    
    // int mina, minb;
    // heap h;

    // int sum = AlgHeap ( getSize(data),
    //                     getVecX(data),
    //                              getVecY(data),
    //                              getCompatibilityMtx(data),
    //                     &mina,
    //                     &minb,
    //                     h );
    
    // printf("%d %d %d\n", mina, minb, sum);
    
    // destroy_data(data);
    
    // for ( int i = 0; i < MAXN; i++ ) {
    //     free(hash[i]);
    // }
    
    // free(hash);

    return 0;
}
