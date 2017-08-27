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

#define MAXN 100
#define PROB 10
#define REP  50

const string DATA_PATH = "./data/stats_";
const string INST_PATH = "./instances/";

using namespace std;

void print_state (const std::ios& stream) {
  std::cout << " good()=" << stream.good() << endl;
  std::cout << " eof()=" << stream.eof() << endl;
  std::cout << " fail()=" << stream.fail() << endl;
  std::cout << " bad()=" << stream.bad() << endl;
}

double getElapsedTime( clock_t start, clock_t end ) {
    return (double) (end-start)*1000/CLOCKS_PER_SEC;
}

int main( int argc, char const *argv[] ) {

    int i, j;

    clock_t start, end;

    ofstream fp_stats_diagonal,
             fp_stats_contourl,
             fp_stats_atrivial,
             fp_stats_trivial,
             fp_stats_heap;

    string  inst_fpath;

    fp_stats_diagonal.open( DATA_PATH + "diagonal.txt", std::ofstream::out | std::ofstream::app );
    fp_stats_contourl.open( DATA_PATH + "contourl.txt", std::ofstream::out | std::ofstream::app );
    fp_stats_atrivial.open( DATA_PATH + "atrivial.txt", std::ofstream::out | std::ofstream::app );
    fp_stats_trivial .open( DATA_PATH + "trivial.txt" , std::ofstream::out | std::ofstream::app );
    fp_stats_heap    .open( DATA_PATH + "heap.txt"    , std::ofstream::out | std::ofstream::app );

    for ( i = 10; i <= MAXN; i *= 10 ) {
        inst_fpath = INST_PATH + to_string(i) + ".txt";

        Data data = new_data( inst_fpath, PROB_MOD );

        for ( j = 0; j < REP; j++ ) {
            
        }

        destroy_data( data );
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
